# LocaleLib
Localization library for VegaBase

LocaleLib is a C library developed to enable the translation of applications into multiple languages using the AmigaOS Locale technology. This system allows language strings to be translated without recompiling the source code.
Only a simple translation of a template text file and its conversion using an included utility are required.

Each language requires a translation file (called a catalog) named after the program that uses it, in uppercase, with the .catalog extension (for example, VEGA.catalog, WINDD.catalog).
Each catalog file must be placed in a subdirectory named after the target language, in lowercase (for example, italiano, français, deutsch, etc.), inside the Catalogs folder located in the same directory as the application.

All software using this technology can run without catalog files, since the default language (e.g. English) is built into the source code.
Catalogs are binary files in IFF format, and must be compiled from text files using a dedicated compiler.
For this purpose, the LocaleLib package includes the FlexCat catalog compiler. Please refer to its documentation for instructions on creating the catalog descriptor, catalog translator, and include file.
