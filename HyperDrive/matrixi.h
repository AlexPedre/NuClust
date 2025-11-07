
/*********************************************
**** HyperDrive - Integer matrix routines ****
****  (c) 2004-2025, Alessandro Pedretti  ****
*********************************************/


#ifdef HD_FP
#  undef HD_FP
#  undef HD_VP
#  undef HD_UP

#  undef HD_INT
#  undef HD_MTX_FUNC
#endif

#ifdef HD_INTEGER
#  define  HD_FP(X)                     X ## i
#  define  HD_UP(X)                     X ## _I
#  define  HD_VP(X)                     X ## I

#  define  HD_INT                       HD_LONG
#  define  HD_MTX_FUNC(FUNC)            HD_Mtxi_ ## FUNC

#  undef HD_INTEGER
#endif

#ifdef HD_INTEGER_UNSIGNED
#  define  HD_FP(X)                     X ## ui
#  define  HD_UP(X)                     X ## _UI
#  define  HD_VP(X)                     X ## UI

#  define  HD_INT                       HD_ULONG
#  define  HD_MTX_FUNC(FUNC)            HD_Mtxui_ ## FUNC

#  undef HD_INTEGER_UNSIGNED
#endif


/**** Free a generic matrix ****/

HDRIVE_EXTERN HD_VOID HDRIVE_EXPORT HD_MTX_FUNC(Free)(HD_VP(HD_MTX) Mtx)
{
  if (!Mtx) {
    GlobErrCode = HD_ERR_ILLPAR;
    return;
  }

  HD_FreeSafe(Mtx -> Data);
  HD_Free(Mtx);
  GlobErrCode = HD_ERR_NONE;
}


/**** Create a generic matrix ****/

HDRIVE_EXTERN HD_VP(HD_MTX) HDRIVE_EXPORT HD_MTX_FUNC(New)(HD_ULONG Col, HD_ULONG Row)
{
  HD_VP(HD_MTX)         Mtx;

  if ((!Col) && (!Row)) {
    GlobErrCode = HD_ERR_ILLPAR;
    return HD_NULL;
  }

  if ((Mtx = (HD_VP(HD_MTX))HD_Malloc(sizeof(HD_FP(struct __hd_mtx)))) == HD_NULL)
    return HD_NULL;

  if ((Mtx -> Data = (HD_INT *)HD_Calloc(sizeof(HD_INT) * Col * Row)) == HD_NULL) {
    HD_Free(Mtx);
    return HD_NULL;
  }

  GlobErrCode = HD_ERR_NONE;
  Mtx -> Col  = Col;
  Mtx -> Row  = Row;

  return Mtx;
}

