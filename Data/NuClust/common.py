#!/usr/bin/env python3.6
#coding=CP1252

#********************************************
#****   NuClust - Build DNA/RNA folding  ****
#****        Shared Python code          ****
#**** (c) 2022-2024, Alessandro Pedretti ****
#********************************************


#**** Libraries ****

import getopt
import os
import os.path
import sys

try:
  import pandas as Pd
except:
  print('ERROR: Pandas not installed')
  sys.exit(2)
# End try

try:
  import openpyxl
except:
  print('ERROR: Openpyxl not installed (required by Pandas)')
  sys.exit(2)
# End try

from copy import deepcopy
from datetime import datetime
from sys import stdout

try:
  from openmm.app import *
  from openmm import *
  from openmm.unit import *
  from openmm.vec3 import Vec3
except:
  print('ERROR: OpenMM not installed')
  sys.exit(2)
# End try

#**** Global properties ****

FilePrefix            = ''                   # File name prefix
PdbFileName           = ''                   # PDB file name
PlatformName          = ''                   # Platform name

#****************************
#**** Default parameters ****
#****************************

#**** Energy minimization ****

MinSteps              = 50000                # Minimization steps

#**** Simulated annealing ****
  
SaCycles              = 5                    # Number of cycles
SaEquilSteps          = 10000                # Equilibration steps
SaSteps               = 1000                 # MD steps for incremet
SaTempInc             = 10                   # Temperature increment
SaTempMax             = 800                  # Max temperature
SaTempMin             = 300                  # Min temperature

#**** Generic MD parameters ****

Temperature           = 300                  # Temperature (K)
UseBackboneRestraints = False                # Use backbone restraints
WaterBoxInc           = 2.0 * nanometers     # Water box increment

#**** Heating ****

NvtSteps              = 50000                # Heating steps
NvtTempInc            = 5                    # Temperature increment

#**** Equilibration ****

NptSteps              = 50000                # Equilibration steps
NptUpdateConstrFreq   = 100                  # Update frequency of constraints

#**** Production dynamics ****

DcdPeriod             = 5000                 # Trajectory update frequency
DynSteps              = 500000               # Molecular dynamics steps (1 ns)


#***********************
#**** Internal data ****
#***********************

Copyright    = '2023'
Version      = '1.0.1'
 

#**** Main code ****

def Run():
  Args          = sys.argv[1:]
  DeleteFile    = False
  SaTempMax_    = SaTempMax
  
  #**** Parse the arguments ****
    
  try:
    Opts, Args = getopt.getopt(Args, "ch")
    
    for Opt, Arg in Opts:
      if Opt == '-c':
        DeleteFile = True

      elif Opt == '-h':
        raise getopt.GetoptError("")
    # End of for (Opt, Arg)

  except getopt.GetoptError as Err:
    if str(Err) != '':
      print("\nERROR: " + str(Err) + ".")

    print(f"\n"
          f"{FilePrefix} {Version} - (c) {Copyright}, Alessandro Pedretti\n"
          f"\n"
          f"Usage: {FilePrefix}.py -ch\n"
          f"\n"
          f" c -> Remove all the output files\n"
          f" h -> Show this help\n"
          f"\n"
          f"Examples:\n"
          f"  {FilePrefix}.py -c\n")
    sys.exit(2)
  # End of try
  
  #**** File names ****
  
  CsvFileName   = FilePrefix + '_aq_dyn.csv' 
  DynFileName   = FilePrefix + '_aq_dyn.dcd' 
  EquilFileName = FilePrefix + '_aq_equil.chk' 
  HeatFileName  = FilePrefix + '_aq_heat.chk' 
  LogFileName   = FilePrefix + '.log' 
  MinFileName   = FilePrefix + '_aq_min.pdb' 
  RestrFileName = FilePrefix + '_restr.txt'
  RstFileName   = FilePrefix + '_aq_dyn.chk'
  SaFileName    = FilePrefix + '_sa_min.pdb'
  XlsxFileName  = FilePrefix + '_aq_dyn.xlsx'
  
  LogStart(LogFileName)
  
  print(f"\n"
        f"**** OpenMM DNA/RNA builder ****\n"
        f"\n"
        f"Platform.....................: {PlatformName}\n"
        f"File name prefix.............: {FilePrefix}\n"
        f"PDB file name................: {PdbFileName}\n"
        f"\n"
        f"Energy minimization:\n"
        f"Minimization steps...........: {MinSteps}\n"
        f"\n"
        f"Simulated annealing:\n"
        f"Heating/cooling cycles.......: {SaCycles}\n"
        f"Heating/cooling steps........: {SaSteps}\n"
        f"Equilibration steps. ........: {SaEquilSteps}\n"
        f"Max. temperature.............: {SaTempMax_}\n"
        f"Min. temperature.............: {SaTempMin}\n"
        f"Temperature increment........: {SaTempInc}\n"
        f"\n"
        f"Simulation parameters:\n"
        f"Heating steps................: {NvtSteps}\n"
        f"  Temperature increment......: {NvtTempInc}\n"
        f"Equilibration steps. ........: {NptSteps} ({NptSteps * 2 / 1000} ps)\n"
        f"Dynamics steps...............: {DynSteps} ({DynSteps * 2 / 1000000} ns)\n"
        f"Trajectoty update frequency..: {DcdPeriod}\n"
        f"Use backbone restraints......: {UseBackboneRestraints}\n"
        f"  Update frequency...........: {NptUpdateConstrFreq}\n"
        f"Temperature..................: {Temperature} K\n")

  #**** Remove all the output files ****
  
  if (DeleteFile):
    print('* Removing the output files')
    
    FilesToRemove = [ CsvFileName, DynFileName, EquilFileName, HeatFileName, MinFileName,
                      RstFileName, SaFileName , XlsxFileName ]
    
    for FileName in FilesToRemove:
      if os.path.isfile(FileName):
        os.remove(FileName)
      # End if
    # End of for (FileName)
  #end if

  #**** Setup the platform ****

  hPlatform = Platform.getPlatformByName(PlatformName)
  
  #**** Check if the simulated annealing was already performed ****

  if not os.path.exists(SaFileName):
  
    #**** Setup the system ****

    hForceField = ForceField('amber14-all.xml', 'amber14/RNA.OL3.xml')
    hPdb        = PDBFile(PdbFileName)
        
    #**** Setup the MM engine ****

    hSystem     = hForceField.createSystem(hPdb.topology, nonbondedMethod = CutoffNonPeriodic, nonbondedCutoff = 1 * nanometer, constraints = HBonds)
    hIntegrator = LangevinMiddleIntegrator(Temperature * kelvin, 1.0 / picosecond, 2.0 * femtosecond)
  
    #**** Restraints (before Simulation() !!!) ****
  
    print('* Loading the restraints')
    RestrLoad(RestrFileName, hSystem)
    
    #**** Setup the simulation ****
    
    hSimulation = Simulation(hPdb.topology, hSystem, hIntegrator, hPlatform)

    #**** Minimize the structure ****

    print(f'* Minimizing the structure ({MinSteps} steps)')
    hSimulation.context.setPositions(hPdb.positions)
    hSimulation.minimizeEnergy(maxIterations = MinSteps) 
    PrintEnergy(hSimulation)
    
    #**** Simulated annealing ****
    
    print(f'* Running the simulated annealing ({SaCycles} cycles)')
    
    if (SaCycles <= 1): SaTempMax_Dec = SaTempMax_;
    else: SaTempMax_Dec = (SaTempMax_ - SaTempMin) / (SaCycles - 1)
    
    # hSimulation.reporters.append(DCDReporter(FilePrefix + '_sa.dcd', DcdPeriod))   
    
    for k in range(1, SaCycles + 1):
      print(f'\n  Cycle #{k}')

      #**** Heating ****

      print(f'    Heating from 0 to {SaTempMax_} K')
      for i in range(SaTempInc, SaTempMax_ + SaTempInc, SaTempInc):
        hIntegrator.setTemperature(i * kelvin)
        hSimulation.step(SaSteps)
      # End of for (i)
        
      #**** Equilibration ****
      
      print(f'    Equilibrating at {SaTempMax_} K')
      hSimulation.step(SaEquilSteps)

      #**** Cooling ****

      print(f'    Cooling from {SaTempMax_} to 0 K')
      for i in range(SaTempMax_, -SaTempInc, -SaTempInc):
        if i < 0: i = 0
        hIntegrator.setTemperature(i * kelvin)
        hSimulation.step(SaSteps)
      # End of for (i)
      
      if k == SaCycles - 1: SaTempMax_ = SaTempMin
      else: SaTempMax_ = int(SaTempMax_ - SaTempMax_Dec)
    # End of for (k)

    #**** Minimize the structure ****

    print(f'\n* Minimizing the structure ({MinSteps} steps)')
    hSimulation.minimizeEnergy(maxIterations = MinSteps) 
    PrintEnergy(hSimulation)

    #**** Save the PDB file ****
    
    Positions = hSimulation.context.getState(getPositions = True).getPositions()
    PdbSave(SaFileName, hSimulation.topology, Positions)
    
  else:
    print(f'* Simulated annealing already performed')
  # End if


  #**** Prepare the structure for the molecular dynamics ****

  hForceField = ForceField('amber14-all.xml', 'amber14/tip3pfb.xml', 'amber14/RNA.OL3.xml')
  Minimize    = False
  
  if not os.path.exists(MinFileName):
    hPdb        = PDBFile(SaFileName)
    hModeller   = Modeller(hPdb.topology, hPdb.positions)
  
    #**** Calculate the water box size ****

    print('* Calculating the water box size')        
    AtmNum = 0
    for x, y, z in hModeller.positions:
      if AtmNum:
        if x > MaxX: MaxX = x
        if y > MaxY: MaxY = y
        if z > MaxZ: MaxZ = z
        if x < MinX: MinX = x
        if y < MinY: MinY = y
        if z < MinZ: MinZ = z
      else:
        MaxX = MinX = x
        MaxY = MinY = y
        MaxZ = MinZ = z
      # End if
      AtmNum += 1
    # End of for (x, y, z)
    WaterBoxSize = Vec3(MaxX - MinX + WaterBoxInc, MaxY - MinY + WaterBoxInc, MaxZ - MinZ + WaterBoxInc) / nanometer
    print(f"  {WaterBoxSize.x} x {WaterBoxSize.y} x {WaterBoxSize.z} nm")

    #**** Add the solvent ****

    print('* Adding solvent')
    hModeller.addSolvent(hForceField, boxSize = WaterBoxSize * nanometer)
    Positions = hModeller.positions
    Topology  = hModeller.topology
    Minimize  = True
  
  else:
  
    print(f'* Loading {MinFileName}')
    hPdb         = PDBFile(MinFileName)
    Positions    = hPdb.positions
    Topology     = hPdb.topology
    WaterBoxSize = Topology.getUnitCellDimensions() / nanometer
    
    print(f"  Periodic box size: {WaterBoxSize.x} x {WaterBoxSize.y} x {WaterBoxSize.z} nm")
  # End if
  
  #**** Setup the MM engine ****

  hSystem     = hForceField.createSystem(Topology, nonbondedMethod = PME, nonbondedCutoff = 1 * nanometer, constraints = HBonds)
  hIntegrator = LangevinMiddleIntegrator(Temperature * kelvin, 1.0 / picosecond, 2.0 * femtosecond)

  #**** Restraints ****

  print('* Loading the restraints')
  RestrLoad(RestrFileName, hSystem)

  hSimulation = Simulation(Topology, hSystem, hIntegrator, hPlatform)
  hSystem.setDefaultPeriodicBoxVectors(Vec3(WaterBoxSize.x, 0, 0), Vec3(0, WaterBoxSize.y, 0), Vec3(0, 0, WaterBoxSize.z))
  hSimulation.context.setPositions(Positions)
  hSimulation.context.setPeriodicBoxVectors(Vec3(WaterBoxSize.x, 0, 0), Vec3(0, WaterBoxSize.y, 0), Vec3(0, 0, WaterBoxSize.z))

  #**** Minimize the cluster ****

  if Minimize:
    print(f'* Minimizing the cluster ({MinSteps} steps)')
    StartTime = datetime.now()
    hSimulation.minimizeEnergy(maxIterations = MinSteps)
    StartTime = datetime.now() - StartTime
    PrintEnergy(hSimulation)
    print(f'  Elapsed time {StartTime}')
    print(f'* Saving {MinFileName}')
    Positions = hSimulation.context.getState(getPositions = True).getPositions()
    PdbSave(MinFileName, hSimulation.topology, Positions)
  # End if

  #**** NVT heating ****
  
  if os.path.exists(HeatFileName):
    if not os.path.exists(EquilFileName):
      print(f'* Loading heating {HeatFileName}')
      hSimulation.loadCheckpoint(HeatFileName)
      PrintEnergy(hSimulation)
    else:
      print('* Heating skipped')
    # End if
  elif NvtSteps:
    print(f'* Heating the system to {Temperature} K')
    NvtDeltaT     = NvtTempInc
    NvtIter       = int(Temperature / NvtTempInc)
    NvtDeltaSteps = int(NvtSteps / NvtIter)
    StartTime     = datetime.now()
    hSimulation.context.setVelocitiesToTemperature(NvtDeltaT * kelvin)
    for i in range(NvtIter):
      Temp = (NvtDeltaT + (i * NvtDeltaT))
      if not i % 10:
        print('  %-3d T = %d K' % (i, Temp))
      hSimulation.step(NvtDeltaSteps)
      hIntegrator.setTemperature(Temp * kelvin)
    # End of for (i)
    StartTime = datetime.now() - StartTime
    print('  %-3d T = %d K' % (NvtIter, Temp))
    PrintEnergy(hSimulation)
    print(f'  Elapsed time {StartTime}')
    hSimulation.saveCheckpoint(HeatFileName)
  # End if

  #**** NPT equilibration ****
  
  if os.path.exists(EquilFileName):
    if os.path.exists(RstFileName):
      print('* Equilibration skipped')
    else:
      print(f'* Loading equilibration {EquilFileName}')
      hSimulation.loadCheckpoint(EquilFileName)
    # End if
  else:
    print(f'* Equilibrating the system')
    hSimulation.context.reinitialize(True)
    hSimulation.reporters.clear()
    if UseBackboneRestraints:
      hSystem.addForce(MonteCarloBarostat(1 * atmosphere, Temperature * kelvin))
      NptDeltaSteps = int(NptSteps / NptUpdateConstrFreq)
      StartTime     = datetime.now()
      for i in range(NptUpdateConstrFreq):
        hSimulation.step(NptDeltaSteps)
        hSimulation.context.setParameter('k', (float(99.02 - (i * 0.98)) * kilocalories_per_mole / angstroms ** 2))
      # End of for (i)
      StartTime = datetime.now() - StartTime
      PrintEnergy(hSimulation)
      print(f'  Elapsed time {StartTime}')
    else:  
      # hSimulation.reporters.append(StateDataReporter(stdout, DcdPeriod, step=True, potentialEnergy=True, temperature=True))
      # hSimulation.reporters.append(DCDReporter("Pippo.dcd", DcdPeriod, enforcePeriodicBox = False))      
      StartTime = datetime.now()
      hSimulation.step(NptSteps)
      StartTime = datetime.now() - StartTime
      PrintEnergy(hSimulation)
      print(f'  Elapsed time {StartTime}')
    # End if
    hSimulation.saveCheckpoint(EquilFileName)
  # End if

  #**** Production molecular dynamics ****

  hSimulation.context.reinitialize(True)
  hSimulation.context.setTime(0)
  
  #**** Perform the restart ****
  
  if os.path.exists(RstFileName):
    print('* Restarting the molecular dynamics')
    hSimulation.loadCheckpoint(RstFileName)
    
    #**** Find out how many steps to run left ****
    
    CsvLog   = [ i for i in open(CsvFileName).readlines() ]
    LastStep = int(CsvLog[-1].split(';')[0])
    RemSteps = DynSteps - LastStep
    
    print(f'  Restarting from {LastStep}/{DynSteps}')

    DcdOpenMode             = 'a'
    hSimulation.currentStep = LastStep
    Restart                 = True
  else:
    print('* Running the molecular dynamics')
    DcdOpenMode             = 'w'
    hSimulation.currentStep = 0      
    RemSteps                = DynSteps
    Restart                 = False
  # End if

  if RemSteps > 0:
    hSimulation.reporters.clear()
    hSimulation.reporters.append(CheckpointReporter(RstFileName, DcdPeriod))
    hSimulation.reporters.append(DCDReporter(DynFileName, DcdPeriod, enforcePeriodicBox = True, append = Restart))
    hSimulation.reporters.append(StateDataReporter(open(CsvFileName, 'w'), DcdPeriod,
                                                   step = True,
                                                   potentialEnergy = True, kineticEnergy = True, totalEnergy = True,
                                                   temperature = True,
                                                   remainingTime = True, speed = True, totalSteps = RemSteps,
                                                   separator = ';'))
  
    StartTime = datetime.now()
    hSimulation.step(RemSteps)
    StartTime = datetime.now() - StartTime
    PrintEnergy(hSimulation)
    print(f'  Elapsed time {StartTime}')
    
    #**** Convert the output to excel ****
    
    print('  Converting the energy file to Excel')
    try:
      DataFrame = Pd.read_csv(CsvFileName, sep = ';')
      DataFrame.rename(columns = {DataFrame.columns[0]: "Step"}, inplace = True)
      DataFrame.to_excel(XlsxFileName, index = None, header = True)
    except:
      Error("Can't write the Excel file")
  else:
    print('  Nothing to do')
  # End if
  
  print('* Done')
# End of Main()


#**** Log class ****

class LogClass:
  def __init__(self, filename):
    self.terminal = sys.stdout
    self.logfile  = open(filename, "w", buffering = 1)

  def write(self, message):
    self.terminal.write(message)
    self.logfile.write(message)

  def flush(self):
    pass
# End of class


#**** Show an error ****

def Error(Err):
  print(f"\nERROR: {Err}.\n")
  sys.exit(2)
# End of Error()
  

#**** Start logging ****

def LogStart(FileName):
  sys.stdout = LogClass(FileName)
  sys.stderr = sys.stdout
# End of LogStart()


#**** Stop logging ****

def LogStop():
  sys.stdout.logfile.close()
  sys.stdout = sys.stdout.terminal
  sys.stderr = sys.stderr.terminal
# End of LogStop()


#**** Format the PDB indexes ****

def PdbFormatIndex(Index, Places):
  if Index < 10 ** Places:
    Format = f'%{Places}d'
    return Format % Index
  # End if

  Format       = f'%{Places}X'
  ShiftedIndex = (Index - 10 ** Places + 10 * 16 ** (Places-1)) % (16 ** Places)
  return Format % ShiftedIndex
# End of PdbFormatIndex()


#**** Save PDB file ****

def PdbSave(FileName, Top, Pos):
  with open(FileName, 'w+', newline = '\n') as hFile:
    PDBFile.writeHeader(Top, hFile)
    PDBFile.writeModel(Top, Pos, hFile)
    
    #**** Force to save the connectivity ****
    
    atomIndex     = {}
    nextAtomIndex = 0
    prevChain     = None
    for chain in Top.chains():
      for atom in chain.atoms():
        if atom.residue.chain != prevChain:
          nextAtomIndex += 1
          prevChain = atom.residue.chain
        atomIndex[atom] = nextAtomIndex
        nextAtomIndex += 1
      # End of for (atom)
    # End of for (chain)

    atomBonds = {}
    for atom1, atom2 in Top.bonds():
      index1 = atomIndex[atom1]
      index2 = atomIndex[atom2]
      if index1 not in atomBonds:
        atomBonds[index1] = []
      if index2 not in atomBonds:
        atomBonds[index2] = []
      atomBonds[index1].append(index2)
      atomBonds[index2].append(index1)    
    # End of for (atom1, atom2)

    for index1 in sorted(atomBonds):
      bonded = atomBonds[index1]
      while len(bonded) > 4:
        print("CONECT%5s%5s%5s%5s" % (PdbFormatIndex(index1, 5), PdbFormatIndex(bonded[0], 5),
              PdbFormatIndex(bonded[1], 5), PdbFormatIndex(bonded[2], 5)), file = hFile)
        del bonded[:4]
      line = "CONECT%5s" % PdbFormatIndex(index1, 5)
      for index2 in bonded:
        line = "%s%5s" % (line, PdbFormatIndex(index2, 5))
      print(line, file = hFile)
    hFile.write("END\n")
  # End of with
# End of PdbSave()


#**** Print the potential energy ****

def PrintEnergy(hSim):
  print(f'  Potential energy %.3f kJ/mol' %
        (hSim.context.getState(getEnergy = True).getPotentialEnergy() / kilojoule_per_mole))
# End of PrintEnergy()


#**** Load the restraints ****

def RestrLoad(FileName, System):
  """
  Force        = CustomBondForce("step(r-r0) * (k/2) * (r-r0)^2")
  Force.addPerBondParameter('r0')
  Force.addPerBondParameter('k')
  System.addForce(Force)
  """

  with open(FileName) as input_file:
    for Line in input_file:
      Columns = Line.split()
      i       = int(Columns[1]) - 1
      j       = int(Columns[2]) - 1
      r0      = float(Columns[3])
      k       = float(Columns[4])
#      Force.addBond(i, j, [r0, k])  
      System.addConstraint(i, j, r0)
    # End of for (line)
  # End of with   
# End of RestrLoad()
