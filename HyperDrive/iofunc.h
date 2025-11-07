

/*********************************************
****  HyperDrive - Internal I/O functions ****
****  (c) 2004-2025, Alessandro Pedretti  ****
*********************************************/


#ifndef __HD_IOFUNC_H
#  define  __HD_IOFUNC_H

HD_VOID          HD_CALLBACK IoFuncClose(HD_FILE Handle);
HD_FILE          HD_CALLBACK IoFuncOpen(const HD_CHAR *FileName, const HD_CHAR *Mode);
HD_ULONG         HD_CALLBACK IoFuncRead(HD_FILE Handle, HD_VOID *Ptr, HD_ULONG Size);
HD_LONG          HD_CALLBACK IoFuncPrint(HD_FILE Handle, const HD_CHAR *Format, ...);
HD_LONG          HD_CALLBACK IoFuncSeek64(HD_FILE Handle, HD_DLONG Offset, HD_LONG Whence);
HD_DLONG         HD_CALLBACK IoFuncTell64(HD_FILE Handle);
HD_ULONG         HD_CALLBACK IoFuncWrite(HD_FILE Handle, HD_VOID *Ptr, HD_ULONG Size);

#endif

