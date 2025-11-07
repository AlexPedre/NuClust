
/********************************************
****       HyperDrive - Color table      ****
**** Copyright 2004, Alessandro Pedretti ****
********************************************/


#ifndef __HDCOLOR_H
#  define  __HDCOLOR_H

/**** Color structure ****/

typedef struct {
  HD_UBYTE      R, G, B;        /* RGB values               */
  HD_UBYTE      ID;             /* Color ID                 */
} HD_ATM_COLOR;

#ifdef __HD_COLORTABLE
const HD_ATM_COLOR ColorTable[] = {{   0,   0,   0, VGCOL_NONE       },
                                   {   0,   0,   0, VGCOL_BLACK      },
                                   { 255, 255, 255, VGCOL_WHITE      },
                                   { 255,   0,   0, VGCOL_RED        },
                                   {   0, 255,   0, VGCOL_GREEN      },
                                   {   0, 255, 255, VGCOL_CYAN       },
                                   { 255, 255,   0, VGCOL_YELLOW     },
                                   { 178,  34,  32, VGCOL_FIREBIRCK  },
                                   { 255,   0, 255, VGCOL_MAGENTA    },
                                   { 255, 153, 204, VGCOL_PINK       },
                                   { 153,   0, 153, VGCOL_VIOLET     },
                                   { 200, 200, 200, VGCOL_GRAY       },
                                   { 255, 102,   0, VGCOL_ORANGE     },
                                   {  34, 139,  34, VGCOL_DARKGREEN  },
                                   {   0,   0, 255, VGCOL_BLUE       },
                                   { 255, 200,  50, VGCOL_DARKYELLOW },
                                   { 102,  51,  51, VGCOL_BROWN      },
                                   { 143, 143, 255, VGCOL_SKYBLUE    },

                                   { 102, 102, 102, VGCOL_DARKGRAY   },
                                   { 255, 195, 204, VGCOL_GHOSTPINK  },
                                   { 204, 255, 204, VGCOL_GHOSTGREEN },
                                   { 204, 255, 255, VGCOL_GHOSTBLUE  },
                                   { 255, 255, 204, VGCOL_GHOSTYELLOW},
                                   { 229, 229, 229, VGCOL_GHOSTGRAY  },
                                   { 255, 204, 153, VGCOL_SAND       },

                                   {   0,    0,  0, 255               }};
#  else

extern const HD_ATM_COLOR       ColorTable[];

#  endif
#endif
