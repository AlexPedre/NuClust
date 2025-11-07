@echo off
set BAK=%PATH%
set PATH=%PATH%;..\..\..\..\Bin\Win32
..\..\Bin\Mingw32\NuClust %*
set PATH=%BAK%
set BAK=
