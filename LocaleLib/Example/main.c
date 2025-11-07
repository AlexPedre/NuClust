
/*******************************************
****             Hello World            ****
****     with language localization     ****
**** (c) 2001-2025, Alessandro Pedretti ****
*******************************************/


#include <stdio.h>

#ifdef __BORLANDC__
#  pragma hdrstop
#endif

#include "../localelib.h"

#define  HELLOWORLD_ARRAY
#include "globstr.h"

/**** Prototypes ****/

const char *    GetStr(unsigned int);

/**** Global variables ****/

void *          Catalog = NULL;


/**** Main code ****/

int main()
{
  char          Buf[256];

  /**** Print with built-in language ****/

  printf("Built-in string:   \"%s\"\n", GetStr(MSG_HELLO));

  /**** Open the italian catalog ****/

  if ((Catalog = (void *)LocOpenCat("HELLOWORLD.catalog",
                                    ".",
                                    "italiano",
                                    1,
                                    "english")) == NULL) {

    /**** If the catalog isn't found, the built-in language ****/
    /**** is used.                                          ****/

    if ((LocGetErr()) && (LocGetErr() != LOCERR_NOTFOUND)) {
      LocGetErrStr(Buf, 256);
      fprintf(stderr, "%s\n", Buf);
    }
  }

  /**** Print the translated string ****/

  printf("Translated string: \"%s\"\n", GetStr(MSG_HELLO));

  printf("%s", GetStr(MSG_DONE));

  /**** If needed, colse the catalog ****/

  LocCloseCat(Catalog);

  return 0;
}



/**** Return a string and if possible, translate it ****/

const char *GetStr(unsigned int Id)
{
  const char *          BuiltIn = "Unknown localized string";
  register unsigned int k        = sizeof(HELLOWORLD_Str) / sizeof(LOCARRAY);
  register LOCARRAY *   Ptr     = (LOCARRAY *)HELLOWORLD_Str;

  while(k--) {
    if (Ptr -> Id == Id) {
      BuiltIn = Ptr -> Str;
      break;
    }
    ++Ptr;
  }

  /**** String localization ****/

  if (Catalog)
    return((char *)LocGetCatStr((void *)Catalog, Id, BuiltIn));

  return BuiltIn;
}