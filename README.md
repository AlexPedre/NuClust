# NuClust
NUPACK custering tool and 3D DNA builder

## Overview
**NuClust** is a C++ program designed for **biological sequence analysis** and **clustering** (e.g., DNA or RNA).  
It implements **K-Means clustering** combined with **thermodynamic analysis** using **HyperDrive** and **VEGA** SDKs. 

The software groups similar nucleotide sequences based on sequence similarity and calculated energy parameters, supporting research in **bioinformatics**, **aptamer design**, and **oligonucleotide optimization**.

---

## 🧩 System Requirements

### Operating System
- **Linux** or **Windows 7/8/10/11**

### Required Software
- **C++17 compiler**: `g++` or `clang++`
- **MinGW/MinGW-w64** (Windows only), alternatively Embarcadero's RAD Studio/ C++ Builder
- **HyperDrive SDK** (included)
- **VEGA SDK** (included)
- **GNU Make** (optional, recommended)

## 🧱 Installation and Compilation

```bash
git clone https://github.com/AlexPedre/NuClust.git
cd NuClust/NuClust/Targets/YOUR_TARGET
make
```
The precompiled binaries for Linux (x86, x64 and ARM) and Windows (x86 and x64) are in NuClust/NuClust/Bin directory.
