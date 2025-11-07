
/********************************************
****      NuClust - AptaMat distance     ****
**** (c) 2022-2025 - Alessandro Pedretti ****
********************************************/


#include <stdio.h>
#include <string.h>

#include <hdfile.h>
#include <hdstring.h>
#include <math.h>

#include <vgbase.h>
#include <vgdna.h>
#include <vghdstrutils.h>
#include <vgpk_def.h>

#ifdef __BORLANDC__
#  pragma hdrstop
#  pragma argsused
#endif

#include "aptamat.h"


static HD_LONG gap_penalty_matrix[] = {1, 1};


/**** Dotbracket constructor ****/

/*
HD_FASTCALL Dotbracket::Dotbracket(const HDC_String &MyDotbracket, HD_LONG *gap_penalty)
{
  if (!gap_penalty) gap_penalty = gap_penalty_matrix;
}
*/


