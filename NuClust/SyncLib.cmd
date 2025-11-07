@echo off
echo Synchronizing the libraries...
echo.

echo * Windows x86
set SRC=..\..\Bin\Win32
set DEST=Bin\RADS_Win32
copy %SRC%\hdrive.dll %DEST%
copy %SRC%\locale.dll %DEST%
copy %SRC%\vegabase.dll %DEST%

echo * Windows x64
set SRC=..\..\Bin\Win64
set DEST=Bin\RADS_Win64
copy %SRC%\hdrive.dll %DEST%
copy %SRC%\locale.dll %DEST%
copy %SRC%\vegabase.dll %DEST%

set SRC=
set DEST=
echo.
pause
