
/*******************************************
****     HyperDrive - Font routines     ****
**** (c) 2004-2025, Alessandro Pedretti ****
*******************************************/


#ifndef __HDFONT_H
#  define  __HDFONT_H

#  include "hdstring.h"

/**** Pitch types ****/

#  define  HD_PITCH_FIXED               0
#  define  HD_PITCH_VARIABLE            1

/**** Font styles ****/

#  define  HD_FONT_STYLE_NORMAL         0
#  define  HD_FONT_STYLE_BOLD           1
#  define  HD_FONT_STYLE_ITALIC         2
#  define  HD_FONT_STYLE_UNDERLINE      4

/**** Font flags ****/

#  define  HD_FONT_FLG_NONE             0
#  define  HD_FONT_FLG_FREEUSERDATA     1

/**** Default settings ****/

#  define  HD_FONT_DEF_PITCH            HD_PITCH_VARIABLE
#  define  HD_FONT_DEF_SIZE             10
#  define  HD_FONT_DEF_STYLE            HD_FONT_STYLE_NORMAL

#  ifdef AMIGA
#    define HD_FONT_DEF_NAME            "Topaz"
#  endif

#  ifdef WIN32
#    define HD_FONT_DEF_NAME            "MS Sans Serif"
#  endif

#  ifndef HD_FONT_DEF_NAME
#    define  HD_FONT_DEF_NAME           "Helvetica"
#  endif

/**** Text alignment ****/

#  define  HD_TXT_ALIGN_LEFT            0x00
#  define  HD_TXT_ALIGN_RIGHT           0x01
#  define  HD_TXT_ALIGN_CENTER          0x02

#  define  HD_TXT_ALIGN_TOP             0x00
#  define  HD_TXT_ALIGN_BOTTOM          0x10
#  define  HD_TXT_ALIGN_CENTERV         0x20

/**** Font data ****/

struct __hd_font {
  HD_STRING             Name;           /* Font name                            */
  HD_COLOR              Color;          /* Font color                           */
  HD_LONG               Flags;          /* Flags                                */
  HD_LONG               Pitch;          /* Font pitch                           */
  HD_LONG               Style;          /* Font style                           */

  HD_VOID *             UserData;       /* Pointer to user data                 */
  HD_LONG               UserTag;        /* User tag                             */
};

typedef struct __hd_font *      HD_FONT;

/**** Macros ****/

#  define  HD_FONT_SIZE         sizeof(struct __hd_font)


/**** Add leading underscores to exported functions ****/

#  ifdef HD_USE_LEADING_UNDERSCORE
#    define  HD_StrFree                 _HD_StrFree
#    define  HD_StrNew                  _HD_StrNew
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
   extern "C" {
#  endif

HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT  HD_FontFree(HD_FONT Font);
HDRIVE_EXTERN HD_FONT           HDRIVE_EXPORT  HD_FontNew(HD_VOID);

#  ifdef __cplusplus
   }
#  endif
#endif
