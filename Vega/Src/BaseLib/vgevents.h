
/*************************************************
****   VEGA ZZ - User defined window events   ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef VG_EVENTS_H
#  define  VG_EVENTS_H


/**** Windows custom messages ****/

#  ifdef WIN32
#    define  WM_USER_GLDRAW       (WM_USER     ) /* Force the OpenGL draw  */
// #    define  WM_USER_DESTROY      (WM_USER +  1) /* Destroy a C++ object   */
#    define  WM_USER_GLGRAB       (WM_USER +  2) /* Grab the OpenGL window */
#    define  WM_USER_COMMAND      (WM_USER +  3) /* Process a command      */
#    define  WM_USER_CLOSETHREAD  (WM_USER +  4) /* Close a thread handle  */
#    define  WM_USER_DEMO         (WM_USER +  5) /* Demo call              */
#    define  WM_USER_JOYSTICK     (WM_USER +  6) /* JoyStick callback      */
#    define  WM_USER_EXITMSGLOOP  (WM_USER +  7) /* Exit from message loop */
#    define  WM_USER_PROGBAR      (WM_USER +  8) /* Progress bar           */
#    define  WM_USER_GLDRAWFAST   (WM_USER +  9) /* OpenGL draw fast       */
#    define  WM_USER_CURSORBUSY   (WM_USER + 10) /* Busy cursor            */
#    define  WM_USER_SHUTDOWN     (WM_USER + 11) /* Shutdown the system    */
#    define  WM_USER_FORCECLOSE   (WM_USER + 12) /* Close all without ask  */
#    define  WM_USER_UPDDIALOGS   (WM_USER + 13) /* Update the dialogs     */
#    define  WM_USER_TURBOMODE    (WM_USER + 14) /* Enable/disable turbo   */
#    define  WM_USER_PROGWAITEND  (WM_USER + 15) /* Progbar wait end       */
#    define  WM_USER_OPENVR       (WM_USER + 16) /* OpenVR event           */
#  endif
#endif
