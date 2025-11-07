
/*************************************************
****            Locale library V1.2           ****
****                   Tables                 ****
**** Copyright 2000-2025, Alessandro Pedretti ****
**************************************************/


#ifdef _WIN32_WCE
# pragma warning (disable : 4305)
#endif

/**** Data for automatic language selection ****/

typedef struct {
  short         ID;
  char *        LangStr;
} LANGTAB;

#if defined(WIN32) || defined(_WIN32_WCE)
#  include <windows.h>
#else

enum {
  LANG_CATALAN = 0, /* Don't change the order */
  LANG_CROATIAN   ,
  LANG_CZECH      ,
  LANG_DANISH     ,
  LANG_DUTCH      ,
  LANG_ENGLISH    ,
  LANG_ESTONIAN   ,
  LANG_FINNISH    ,
  LANG_FRENCH     ,
  LANG_GERMAN     ,
  LANG_GREEK      ,
  LANG_HUNGARIAN  ,
  LANG_ICELANDIC  ,
  LANG_ITALIAN    ,
  LANG_JAPANESE   ,
  LANG_NORWEGIAN  ,
  LANG_POLISH     ,
  LANG_PORTUGUESE ,
  LANG_RUSSIAN    ,
  LANG_SERBIAN    ,
  LANG_SLOVAK     ,
  LANG_SLOVENIAN  ,
  LANG_SPANISH    ,
  LANG_SWEDISH    ,
  LANG_TURKISH
};

#endif

static const LANGTAB LangTab[] = {{LANG_CATALAN   , "català"     },  /* Don't change the order */
                                  {LANG_CROATIAN  , "hrvatski"   },
                                  {LANG_CZECH     , "czech"      },
                                  {LANG_DANISH    , "dansk"      },
                                  {LANG_DUTCH     , "nederlands" },
                                  {LANG_ENGLISH   , "english"    },
                                  {LANG_ESTONIAN  , "eesti"      },
                                  {LANG_FINNISH   , "suomi"      },
                                  {LANG_FRENCH    , "français"   },
                                  {LANG_GERMAN    , "deutsch"    },
                                  {LANG_GREEK     , "greek"      },
                                  {LANG_HUNGARIAN , "magyar"     },
                                  {LANG_ICELANDIC , "íslenska"   },
                                  {LANG_ITALIAN   , "italiano"   },
                                  {LANG_JAPANESE  , "japanese"   },
                                  {LANG_NORWEGIAN , "norsk"      },
                                  {LANG_POLISH    , "polski"     },
                                  {LANG_PORTUGUESE, "português"  },
                                  {LANG_RUSSIAN   , "russian"    },
                                  {LANG_SERBIAN   , "srpski"     },
                                  {LANG_SLOVAK    , "slovençina" },
                                  {LANG_SLOVENIAN , "slovensko"  },
                                  {LANG_SPANISH   , "español"    },
                                  {LANG_SWEDISH   , "svenska"    },
                                  {LANG_TURKISH   , "türkçe"     },
                                  {0              , NULL         }
                                 };

/* Data for IBM PC to ISO Latin-1 code conversions.  */

typedef struct {
  char  Dos, Iso;
} KNOWN_PAIRS;

static KNOWN_PAIRS KnownPairs[] =
  {
    { 20, 182},     /* pilcrow sign */
    { 21, 167},     /* section sign */

    {128, 199},     /* capital letter C with cedilla */
    {129, 252},     /* small letter u with diaeresis */
    {130, 233},     /* small letter e with acute accent */
    {131, 226},     /* small letter a with circumflex accent */
    {132, 228},     /* small letter a with diaeresis */
    {133, 224},     /* small letter a with grave accent */
    {134, 229},     /* small letter a with ring above */
    {135, 231},     /* small letter c with cedilla */
    {136, 234},     /* small letter e with circumflex accent */
    {137, 235},     /* small letter e with diaeresis */
    {138, 232},     /* small letter e with grave accent */
    {139, 239},     /* small letter i with diaeresis */
    {140, 238},     /* small letter i with circumflex accent */
    {141, 236},     /* small letter i with grave accent */
    {142, 196},     /* capital letter A with diaeresis */
    {143, 197},     /* capital letter A with ring above */
    {144, 201},     /* capital letter E with acute accent */
    {145, 230},     /* small ligature a with e */
    {146, 198},     /* capital ligature A with E */
    {147, 244},     /* small letter o with circumblex accent */
    {148, 246},     /* small letter o with diaeresis */
    {149, 242},     /* small letter o with grave accent */
    {150, 251},     /* small letter u with circumflex accent */
    {151, 249},     /* small letter u with grave accent */
    {152, 255},     /* small letter y with diaeresis */
    {153, 214},     /* capital letter O with diaeresis */
    {154, 220},     /* capital letter U with diaeresis */
    {155, 162},     /* cent sign */
    {156, 163},     /* pound sign */
    {157, 165},     /* yen sign */
    {160, 225},     /* small letter a with acute accent */
    {161, 237},     /* small letter i with acute accent */
    {162, 243},     /* small letter o with acute accent */
    {163, 250},     /* small letter u with acute accent */
    {164, 241},     /* small letter n with tilde */
    {165, 209},     /* capital letter N with tilde */
    {166, 170},     /* feminine ordinal indicator */
    {167, 186},     /* masculine ordinal indicator */
    {168, 191},     /* inverted question mark */
    {170, 172},     /* not sign */
    {171, 189},     /* vulgar fraction one half */
    {172, 188},     /* vulgar fraction one quarter */
    {173, 161},     /* inverted exclamation mark */
    {174, 171},     /* left angle quotation mark */
    {175, 187},     /* right angle quotation mark */
    {225, 223},     /* small german letter sharp s */
    {230, 181},     /* small Greek letter mu micro sign */
    {241, 177},     /* plus-minus sign */
    {246, 247},     /* division sign */
    {248, 176},     /* degree sign */
    {250, 183},     /* middle dot */
    {253, 178},     /* superscript two */
    {255, 160},     /* no-break space */
    {  0,   0}
  };

