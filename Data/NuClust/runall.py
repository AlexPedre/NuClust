#!/usr/bin/env python3.6
#coding=CP1252

#********************************************
#****   NuClust - Build DNA/RNA folding  ****
#**** (c) 2022-2024, Alessandro Pedretti ****
#********************************************


#**** Libraries ****

import os
import os.path
import sys
import subprocess

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

#**** Scripts to run ****

PrefixList = [
{PREFIXLIST}
]

#**** Open the log file ****

BaseFileName = os.path.splitext(os.path.basename(__file__))[0]
hLog         = open(BaseFileName + '.log', "w", buffering = 1)

hLog.write('\n'
           '*************************\n'
           '**** Master log file ****\n' 
           '*************************\n'
           '\n')

#**** Run the calculations ****

with open(BaseFileName + '.csv', 'w') as hCsv:
  hCsv.write("Structure;FirstStep;FirstEnergy;MinStep;MinEnergy;LastStep;LastEnergy\n")
  for Prefix in PrefixList:
    hLog.write(f'\n* Running {Prefix}\n')
    RetCode = subprocess.call(['python', Prefix + '.py'])
    if RetCode == 0:
      hLog.write('  Completed without errors\n')

      #**** Read the output file ****

      DataFrame = Pd.read_csv(Prefix + '_aq_dyn.csv', sep = ';')       
      DataFrame = DataFrame.reset_index()

      MinEne = 0
      MinStep = 0
      for index, row in DataFrame.iterrows():
        if index == 0:
          FirstEne  = MinEne  = row[2]
          FirstStep = MinStep = row[1]
        elif row[2] < MinEne:
          MinEne  = row[2]
          MinStep = row[1]
        # End if
      # End of for (index, row)
      LastEne  = row[2]
      LastStep = row[1]
      
      #**** Write the energy file ****

      hCsv.write(f"{Prefix};{FirstStep};{FirstEne};{MinStep};{MinEne};{LastStep};{LastEne}\n")

    else:
      print(f'\nERROR: {Prefix} failed\n') 
      hLog.write(f'  ERROR: Return code {RetCode}. Check "{Prefix}.log" file\n')
    # End if
  # End of for (Prefix)
# End of with

#**** Convert the output to Excel ****

try:
  hLog.write('\n* Converting the energy file to Excel\n')
  DataFrame = Pd.read_csv(BaseFileName + '.csv', sep = ';')
  DataFrame.to_excel(BaseFileName + '.xlsx', index = None, header = True)
except:
  print("ERROR: Can't write the Excel file")
# End of try

hLog.write('* Done\n')
hLog.close()
