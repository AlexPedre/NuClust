
/*************************************************
****            Locale library V1.0           ****
****              Private header              ****
**** Copyright 2000-2025, Alessandro Pedretti ****
**************************************************/


#define  IFF_HDRLEN     sizeof(IFFHDR)
#define  IFF_FORM       0x464f524d

/**** Special definitions for IFF catalog files ****/

#define  IFF_CTLG       0x43544C47  /* CTLG chunk */
#define  IFF_CTLG_LANG  0x4C414E47  /* LANG chunk */
#define  IFF_CTLG_STRS  0x53545253  /* STRS chunk */
#define  IFF_CTLG_FVER  0x46564552  /* $VER chunk */

/**** IFF header structure ****/

typedef struct __IFFHdr {
  unsigned int   ID;
  unsigned int   Size;
} IFFHDR;

