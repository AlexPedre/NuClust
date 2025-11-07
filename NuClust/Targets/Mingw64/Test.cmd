@echo off
set BAK=%PATH%
set PATH=%PATH%;..\..\..\..\Bin\Win64
..\..\Bin\Mingw64\NuClust %*
set PATH=%BAK%
set BAK=
