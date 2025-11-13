# NuClust
NUPACK custering tool and DNA structure builder

## Overview
**NuClust** is a C++ program designed for **biological sequence analysis** and **clustering** (e.g., DNA or RNA).  
It implements **K-Means clustering** combined with **thermodynamic analysis** using **HyperDrive** and **VEGA* SDKs.

The software groups similar nucleotide sequences based on sequence similarity and calculated energy parameters, supporting research in **bioinformatics**, **aptamer design**, and **oligonucleotide optimization**.
Optionally, the program is capable of constructing the 3D structure of DNA as a single strand, generating the restraint map for base pairing based on the secondary structure predicted by NUPACK, and producing the input file for the **OpenMM molecular dynamics package** (https://openmm.org/). Specifically, the conversion to 3D involves the following steps:
- Construction of the single-stranded DNA chain;
- Optimization of the initial structure using conjugate gradients energy minimization (50,000 steps, Amber14 force field);
- Execution of simulated annealing while maintaining the restraints: the system is heated from 300 K to 800 K, equilibrated for 10 ps, and then cooled back to 300 K;
- This annealing cycle is repeated five times;
- The resulting structure is further optimized with an additional 50,000 steps of conjugate gradients minimization;
- The optimized structure is inserted into a water box and neutralized with sodium couterions;
- Optimization using conjugate gradients energy minimization (50,000 steps);
- A NVT heating to 300 K is carried out (50000 steps), follwed by NPT equilibration (50000 steps);
- Production MD simulation (NPT, 500000 steps, 1 ns)

All simulation parameters can be chenged (see Data/NuClust/parameters.py)

---

## 🧩 System Requirements

### Operating System
- **Linux** or **Windows 7/8/10/11**

### Required Software
- **C++17 compiler**: `g++` or `clang++`
- **MinGW/MinGW-w64** (Windows only), alternatively Embarcadero's RAD Studio/ C++ Builder
- **HyperDrive SDK** (included)
- **VEGA SDK** (included)
- **OpenMM Package** to build 3D strucure of DNA by simulated annealing

## 🧱 Installation and compilation

```bash
git clone https://github.com/AlexPedre/NuClust.git
cd NuClust/NuClust/Targets/<MY_TARGET>
make
```
The precompiled binaries for Linux (x86, x64 and ARM) and Windows (x86 and x64) are in `NuClust/NuClust/Bin` directory.
Remember to set both VEGADIR and LD_LIBRARY_PATH environment variables to make working the program:
```bash
export VEGADIR="<PACKAGE_ROOT_DIRECTORY>"
export LD_LIBRARY_PATH="$VEGADIR/NuClust/Bin/MY_TARGET $LD_LIBRARY_PATH"
export PATH="$VEGADIR/NuClust/Bin/<MY_TARGET>:$PATH"
```
For Windows OS, you need only to set the VEGADIR enviroment variable:
```bash
set VEGADIR="<PACKAGE_ROOT_DIRECTORY>"
```
## 🧪 Usage
```
NuClust 0.6.1.1 - (c) 2022-2025, Alessandro Pedretti

Usage: NuClust -b[WHAT] -c[CLUSTFILE] -d[DIST] -fh -i[CLUSTMAXITER]
               -k[CLUSTNUM] -n[SEQNAME] -r[SEED] -s[SEQUENCE] -t[TOPNUM] -v NUPACK_FILE

Supported NUPACK input formats:
 csv, txt

Options:
 b -> Build the 3D structures of:
      CLOSEST     = Structures closest to each cluster centroid
      LOWEST      = Structures with the lowest energy of each cluster
      MFE         = Lowest energy structure
      SHARED      = Shared substructure for each cluster
 c -> Output cluster file
 d -> Parameters used to calculate the distance for the cluster analysis:
      APTAMAT     = Matrix-based similarity of secondary structure with MFE
      BP          = Number of base pairs
      DISTANCE    = Distance from MFE
      ENERGY      = Energy hcal/mol
      PROBABILITY = Suboptimal structure probability
      STRUCTURE   = H-bond network
      The parameters must be separated by a space and between double quotes
 f -> Fix the decimal separator according the locale settings
 h -> Show this help
 i -> Maximum number of iterations for cluster analysis (default 1000)
 k -> Number of clusters (default 20)
 n -> Sequence name
 s -> Base sequence (for csv format)
 r -> Seed for random number generator
 t -> Analyze the top ranked suboptimal structures (default 10, 0 = all)
 v -> Save the script to show the restraint in VEGA ZZ

Examples:
 NuClust nupack_file.txt
 NuClust -k 10 -c cluster_file.csv nupack_file.txt
 NuClust -f -c cluster_file.csv -d "Bp Energy Structure" nupack_file.txt NuClust -b shared -c cluster_file.csv -d Structure -v nupack_file.txt
```
