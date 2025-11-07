
/****************************************************************

   This file was created automatically by `FlexCat 2.4'
   from "HELLOWORLD.cd" using HelloWorld.sd 1.0 (07.04.2000)
   Template created by Alessandro Pedretti
   
   To rebuild this include please run:
   flexcat HelloWorld.cd globstr.h=HelloWorld.sd

   Do NOT edit by hand!

****************************************************************/


#define  MSG_HELLO  0
#define  MSG_DONE  1


typedef struct
{
  unsigned int   Id;
  const char     *Str;
} LOCARRAY;


#ifdef HELLOWORLD_ARRAY

static const LOCARRAY HELLOWORLD_Str[] =
{
    { MSG_HELLO, "Hello World !" },
    { MSG_DONE, "Done\n" },
};
#endif /* HELLOWORLD_ARRAY */
