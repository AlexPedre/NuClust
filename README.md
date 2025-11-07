# NuClust
NUPACK custering tool and 3D DNA builder

## Overview
**NuClust** is a C++ program designed for **biological sequence analysis** and **clustering** (e.g., DNA or RNA).  
It implements **K-Means clustering** combined with **thermodynamic analysis** using the **HyperDrive SDK** (VG and HD modules).  

The software groups similar nucleotide sequences based on sequence similarity and calculated energy parameters, supporting research in **bioinformatics**, **aptamer design**, and **oligonucleotide optimization**.

---

## 🧩 System Requirements

### Operating System
- **Linux**, **macOS**, or **Windows 10/11** (with MinGW/MSYS2 environment)

### Required Software
- **C++17 compiler**: `g++` or `clang++`
- **HyperDrive SDK** (required)
- **GNU Make** (optional, recommended)
- (Windows only) `windres` for resource compilation

---

## ⚙️ Installation and Compilation

1. **Extract the archive**
   ```bash
   unzip Src.zip
   cd Src
