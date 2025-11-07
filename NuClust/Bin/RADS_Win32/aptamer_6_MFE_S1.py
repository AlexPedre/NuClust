#!/usr/bin/env python3.6
#coding=CP1252

#********************************************
#****   NuClust - Build DNA/RNA folding  ****
#**** (c) 2022-2023, Alessandro Pedretti ****
#********************************************


#**** Libraries ****

try:
  from openmm.app import *
  from openmm import *
  from openmm.unit import *
  from openmm.vec3 import Vec3
except:
  print('ERROR: OpenMM not installed')
  sys.exit(2)
# End try

try:
  import aptamer_6_com as Nuc
except:
  print("ERROR: Can't find aptamer_6_com.py Python script")
  sys.exit(2)
# End try

#**** Global parameters ****

Nuc.FilePrefix            = 'aptamer_6_MFE_S1'     # File name prefix
Nuc.PlatformName          = 'CUDA'             # Platform name
Nuc.PdbFileName           = 'aptamer_6.pdb'        # PDB file name


#************************************************************
#**** Uncomment the following parameters to override the ****
#**** default configuration                              ****
#************************************************************


#**** Energy minimization ****

# Nuc.MinSteps              = 50000              # Minimization steps

#**** Simulated annealing ****
  
# Nuc.SaCycles              = 5                  # Number of cycles
# Nuc.SaEquilSteps          = 10000              # Equilibration steps
# Nuc.SaSteps               = 1000               # MD steps for incremet
# Nuc.SaTempInc             = 10                 # Temperature increment
# Nuc.SaTempMax             = 800                # Max temperature
# Nuc.SaTempMin             = 300                # Min temperature

#**** Generic MD parameters ****

# Nuc.Temperature           = 300                # Temperature (K)
# Nuc.UseBackboneRestraints = False              # Use backbone restraints
# Nuc.WaterBoxInc           = 2.0 * nanometers   # Water box increment

#**** Heating ****

# Nuc.NvtSteps              = 50000              # Heating steps
# Nuc.NvtTempInc            = 5                  # Temperature increment

#**** Equilibration ****

# Nuc.NptSteps              = 50000              # Equilibration steps
# Nuc.NptUpdateConstrFreq   = 100                # Update frequency of constraints

#**** Production dynamics ****

# Nuc.DcdPeriod             = 5000               # Trajectory update frequency
# Nuc.DynSteps              = 500000             # Molecular dynamics steps (1 ns)

#**** Run the simulation ****

Nuc.Run()
