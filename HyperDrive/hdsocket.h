
/*********************************************
****      HyperDrive - Sockets header     ****
****  (c) 2004-2025, Alessandro Pedretti  ****
*********************************************/


#ifndef __HDSOCKET_H
#  define  __HDSOCKET_H

#  if defined(_WINDOWS) || defined(WINDOWS) || defined(_WIN32) || defined(_WIN32_) || defined(WIN32)
#    include <winsock2.h>
#  endif

#  include <hdstring.h>

/**** Http client flags ****/

#  define  HD_HTTPCLI_NONE              0       /* None                       */
#  define  HD_HTTPCLI_MULTIPART         1       /* Multipart POST             */
#  define  HD_HTTPCLI_SSL               2       /* SSL encoding               */

/**** TCP/IP errors ****/

#  define  HD_ERR_TCP_CONNECT                801 /* Connect error                      */
#  define  HD_ERR_TCP_FILESIZE               802 /* Unable to get the file size        */
#  define  HD_ERR_TCP_HEADER                 803 /* Invalid header                     */
#  define  HD_ERR_TCP_HOSTADDR               804 /* Unable to get the host name        */
#  define  HD_ERR_TCP_INIT                   805 /* Unable to initialize the TCP/IP    */
#  define  HD_ERR_TCP_INVSOCKET              806 /* Invalid socket                     */
#  define  HD_ERR_TCP_MISHOST                807 /* Missing host name                  */
#  define  HD_ERR_TCP_MISURI                 808 /* Missing URI                        */
#  define  HD_ERR_TCP_PORT                   809 /* Invalid port number                */
#  define  HD_ERR_TCP_RECEIVE                810 /* Can't receive data                 */
#  define  HD_ERR_TCP_SEND                   811 /* Can't send data                    */
#  define  HD_ERR_TCP_SOCKET                 812 /* Can't create the socket            */

#  define  HD_ERR_HTTPCLI_BADREQUEST         821 /* Bad request                        */
#  define  HD_ERR_HTTPCLI_CONFLICT           822 /* Conflict                           */
#  define  HD_ERR_HTTPCLI_EXPECTFAIL         823 /* Expectation failed                 */
#  define  HD_ERR_HTTPCLI_FORBIDDEN          824 /* Forbidden                          */
#  define  HD_ERR_HTTPCLI_GONE               825 /* Gone                               */
#  define  HD_ERR_HTTPCLI_HTTP               826 /* Generic HTTP error                 */
#  define  HD_ERR_HTTPCLI_LENGTH             827 /* Length required                    */
#  define  HD_ERR_HTTPCLI_METHOD             828 /* Method not allowed                 */
#  define  HD_ERR_HTTPCLI_NOTACCEPTABLE      829 /* Not accetable                      */
#  define  HD_ERR_HTTPCLI_NOTFOUND           830 /* Not found                          */
#  define  HD_ERR_HTTPCLI_PAYMENT            831 /* Payment required                   */
#  define  HD_ERR_HTTPCLI_PRECONFAIL         832 /* Precondition failed                */
#  define  HD_ERR_HTTPCLI_PROXY              833 /* Proxy authentication required      */
#  define  HD_ERR_HTTPCLI_REQENTTOOLARGE     834 /* Request URI too large              */
#  define  HD_ERR_HTTPCLI_REQRANGE           835 /* Request range not satisfiable      */
#  define  HD_ERR_HTTPCLI_REQURITOOLARGE     836 /* Request URI too large              */
#  define  HD_ERR_HTTPCLI_REQTIMEOUT         837 /* Request timeout                    */
#  define  HD_ERR_HTTPCLI_UNAUTHORIZED       838 /* Unauthorized                       */
#  define  HD_ERR_HTTPCLI_UNSUPMEDIATYP      839 /* Unsupported media type             */
#  define  HD_ERR_HTTPCLI_POSTNOMULTIPART    840 /* Non multipart POST                 */
#  define  HD_ERR_HTTPCLI_POSTCANTMPART      841 /* Can't switch to multipart POST     */
#  define  HD_ERR_HTTPCLI_SSLNOTSUP          842 /* SSL/TSL connection not supported   */

#  define  HD_ERR_MAC_INV                    851 /* Invalid MAC address                */

#  define  HD_ERR_SSL_CTXCREATE              861 /* Can't create OpenSSL context       */
#  define  HD_ERR_SSL_GETCERT                862 /* Can't get the certificate          */
#  define  HD_ERR_SSL_HANDSHAKE              862 /* Unable to handshake with server    */
#  define  HD_ERR_SSL_INIT                   862 /* OpenSSL initialization             */


/**** Macros ****/

#  define  HD_SocketGetBufFree(Skt)         ((Skt) -> InBufLen - (Skt) -> InBufPtr)

/**** Compatibility ****/

#  ifdef WIN32
#    include <process.h>
#    include <direct.h>

#    define  CloseSocket        closesocket

typedef int             socklen_t;

#  else

#    ifndef INVALID_SOCKET
#      define  INVALID_SOCKET     -1
#      define  SOCKET_ERROR       -1
typedef long long       __int64;
typedef int             SOCKET;
#    endif
#    include <pthread.h>
#    include <limits.h>
#    include <linux/limits.h>
#    include <signal.h>
#    include <unistd.h>
#    include <dirent.h>
#    include <sys/socket.h>
#    include <netdb.h>
#    include <netinet/in.h>
#    include <netinet/ip.h>
#    include <arpa/inet.h>

#    define  CloseSocket        close

#endif

/**** Callback prototype ****/

typedef HD_BOOL (HD_CALLBACK *HD_SOCKET_READ)(HD_VOID *Arg, HD_LONG Len);
typedef HD_BOOL (HD_CALLBACK *HD_HTTPCLIENT_GET)(HD_VOID *Arg, HD_LONG CurLen, HD_LONG TotLen);

/**** OpenSSL definitions ****/

#  ifdef HD_USE_SSL
typedef void *          HD_BIO;
typedef void *          HD_SSL;
typedef void *          HD_SSLCTX;
typedef void *          HD_X509;
typedef void *          HD_X509_NAME;
#  endif

/**** Socket data ****/

struct __hd_socket {
  SOCKET                Socket;                 /* Socket                     */
  HD_SOCKET_READ        ReadCallBack;           /* Callback pointer           */
  HD_VOID *             ReadCallBackArg;        /* Callback argument pointer  */

  HD_BOOL               Eof;                    /* EOF flag                   */
  HD_CHAR *             InBuf;                  /* Input buffer pointer       */
  HD_LONG               TimeOut;                /* Connection time-out (sec)  */
  HD_ULONG              InBufLen;               /* Input buffer length        */
  HD_ULONG              InBufPtr;               /* Input buffer position      */
  HD_ULONG              InBufSize;              /* Input buffer size          */
  fd_set                ReadMask;               /* Wait mask for select       */
  struct timeval        TvWaitTimeOut;          /* Wait time out              */

#  ifdef HD_USE_SSL
  HD_SSL                hSsl;                   /* SSL structure              */
  HD_SSLCTX             hSslCtx;                /* SSL context                */
  HD_X509               Cert;                   /* Certificate                */
#  endif
};

typedef struct __hd_socket *            HD_SOCKET;

/**** Http client data ****/

struct __hd_httpclient {
  HD_HTTPCLIENT_GET     GetCallBack;            /* Get callback function      */
  HD_STRING             Agent;                  /* Agent string               */
  HD_STRING             Host;                   /* Remote host name or IP     */
  HD_STRING             Password;               /* Password                   */
  HD_STRING             Uri;                    /* Remote URI to download     */
  HD_STRING             UserName;               /* User name                  */
  HD_LONG               ErrCode;                /* HTTP error code            */
  HD_LONG               TransferEnc;            /* Transfer encoding          */
  HD_VOID *             GetCallBackArg;         /* Get callback argument      */

  /**** Private properties ****/

  HD_LONG               BlockSize;
  HD_LONG               Flags;
  HD_LONG               CurLen;
  HD_LONG               Port;
  HD_LONG               TimeOut;
  HD_SOCKET             Socket;
  HD_STRING             Cookies;
  HD_STRING             PostData;
  HD_UDLONG             TotalLen;
};

typedef struct __hd_httpclient *        HD_HTTPCLIENT;

/**** Add leading underscores to exported functions ****/

#  ifdef HD_USE_LEADING_UNDERSCORE
#    define  HD_HttpClientAddCookie     _HD_HttpClientAddCookie
#    define  HD_HttpClientAddCookieFile _HD_HttpClientAddCookieFile
#    define  HD_HttpClientAddField      _HD_HttpClientAddField
#    define  HD_HttpClientAddFile       _HD_HttpClientAddFile
#    define  HD_HttpClientAddMem        _HD_HttpClientAddMem
#    define  HD_HttpClientFree          _HD_HttpClientFree
#    define  HD_HttpClientGetFile       _HD_HttpClientGetFile
#    define  HD_HttpClientGetFileC      _HD_HttpClientGetFileC
#    define  HD_HttpClientGetMem        _HD_HttpClientGetMem
#    define  HD_HttpClientGetStr        _HD_HttpClientGetStr
#    define  HD_HttpClientNew           _HD_HttpClientNew
#    define  HD_HttpClientParseUrl      _HD_HttpClientParseUrl
#    define  HD_HttpClientParseUrlC     _HD_HttpClientParseUrlC
#    define  HD_HttpClientPostFile      _HD_HttpClientPostFile
#    define  HD_HttpClientPostFileC     _HD_HttpClientPostFileC
#    define  HD_HttpClientPostMem       _HD_HttpClientPostMem
#    define  HD_HttpClientPostStr       _HD_HttpClientPostStr
#    define  HD_HttpClientReset         _HD_HttpClientReset
#    define  HD_HttpClientResetFlags    _HD_HttpClientResetFlags
#    define  HD_HttpClientSetFlags      _HD_HttpClientSetFlags
#    define  HD_HttpClientUnSetFlags    _HD_HttpClientUnSetFlags

#    define  HD_SocketConnect           _HD_SocketConnect
#    define  HD_SocketConnectSSL        _HD_SocketConnectSSL
#    define  HD_SocketFlush             _HD_SocketFlush
#    define  HD_SocketFree              _HD_SocketFree
#    define  HD_SocketGetc              _HD_SocketGetc
#    define  HD_SocketGets              _HD_SocketGets
#    define  HD_SocketGetsC             _HD_SocketGetsC
#    define  HD_SocketNew               _HD_SocketNew
#    define  HD_SocketPuts              _HD_SocketPuts
#    define  HD_SocketPutsC             _HD_SocketPutsC
#    define  HD_SocketRead              _HD_SocketRead
#    define  HD_SocketSetBuf            _HD_SocketSetBuf
#    define  HD_SocketWrite             _HD_SocketWrite

#    define  HD_TcpIpGetIPV4            _HD_TcpIpGetIPV4
#    define  HD_TcpIpGetIPV4C           _HD_TcpIpGetIPV4C
#    define  HD_TcpIpGetIPV4CW          _HD_TcpIpGetIPV4CW
#    define  HD_TcpIpGetIPV4W           _HD_TcpIpGetIPV4W
#    define  HD_TcpIpOnLine             _HD_TcpIpOnLine

#    define  HD_WolSend                 _HD_WolSend
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
   extern "C" {
#  endif

HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_HttpClientAddCookie(HD_HTTPCLIENT Http, const HD_CHAR *Name, const HD_CHAR *Val, const HD_CHAR *Path, const HD_CHAR *Domain, const HD_CHAR *Expires);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_HttpClientAddCookieFile(HD_HTTPCLIENT Http, const HD_CHAR *FileName, const HD_CHAR *Name, const HD_CHAR *Path, const HD_CHAR *Domain, const HD_CHAR *Expires);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_HttpClientAddField(HD_HTTPCLIENT Http, const HD_CHAR *Name, const HD_CHAR *Val);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_HttpClientAddFile(HD_HTTPCLIENT Http, const HD_CHAR *FileName, const HD_CHAR *Name, const HD_CHAR *PostFileName);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_HttpClientAddMem(HD_HTTPCLIENT Http, const HD_CHAR *Name, const HD_CHAR *PostFileName, const HD_VOID *MemPtr, HD_ULONG Len);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_HttpClientFree(HD_HTTPCLIENT Http);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_HttpClientGetFile(HD_HTTPCLIENT Http, HD_STRING FileName);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_HttpClientGetFileC(HD_HTTPCLIENT Http, const HD_CHAR *FileName);
HDRIVE_EXTERN HD_VOID *           HDRIVE_EXPORT HD_HttpClientGetMem(HD_HTTPCLIENT Http, HD_ULONG *Size);
HDRIVE_EXTERN HD_STRING           HDRIVE_EXPORT HD_HttpClientGetStr(HD_HTTPCLIENT Http, HD_STRING Str);
HDRIVE_EXTERN HD_HTTPCLIENT       HDRIVE_EXPORT HD_HttpClientNew(void);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_HttpClientParseUrl(HD_HTTPCLIENT Http, HD_STRING UrlStr);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_HttpClientParseUrlC(HD_HTTPCLIENT Http, const HD_CHAR *UrlStr);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_HttpClientPostFile(HD_HTTPCLIENT Http, HD_STRING FileName);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_HttpClientPostFileC(HD_HTTPCLIENT Http, const HD_CHAR *FileName);
HDRIVE_EXTERN HD_VOID *           HDRIVE_EXPORT HD_HttpClientPostMem(HD_HTTPCLIENT Http, HD_ULONG *Size);
HDRIVE_EXTERN HD_STRING           HDRIVE_EXPORT HD_HttpClientPostStr(HD_HTTPCLIENT Http, HD_STRING Str);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_HttpClientReset(HD_HTTPCLIENT Http);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_HttpClientResetFlags(HD_HTTPCLIENT Http);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_HttpClientSetFlags(HD_HTTPCLIENT Http, HD_LONG Flags);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_HttpClientUnSetFlags(HD_HTTPCLIENT Http, HD_LONG Flags);

HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_SocketConnect(HD_SOCKET Skt, const HD_CHAR *RemoteHost, HD_LONG RemotePort);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_SocketConnectSSL(HD_SOCKET Skt, const HD_CHAR *RemoteHost, HD_LONG RemotePort, HD_LONG Flags);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_SocketFlush(HD_SOCKET Skt, HD_LONG Len);
HDRIVE_EXTERN HD_VOID             HDRIVE_EXPORT HD_SocketFree(HD_SOCKET Skt);
HDRIVE_EXTERN HD_LONG             HDRIVE_EXPORT HD_SocketGetc(HD_SOCKET Skt);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_SocketGets(HD_SOCKET Skt, HD_STRING *Str);
HDRIVE_EXTERN HD_CHAR *           HDRIVE_EXPORT HD_SocketGetsC(HD_SOCKET Skt, HD_CHAR *Str, HD_ULONG Size);
HDRIVE_EXTERN HD_SOCKET           HDRIVE_EXPORT HD_SocketNew(SOCKET Sock);
HDRIVE_EXTERN HD_LONG             HDRIVE_EXPORT HD_SocketPuts(HD_SOCKET Skt, HD_STRING Str);
HDRIVE_EXTERN HD_LONG             HDRIVE_EXPORT HD_SocketPutsC(HD_SOCKET Skt, const HD_CHAR *Str);
HDRIVE_EXTERN HD_LONG             HDRIVE_EXPORT HD_SocketRead(HD_SOCKET Skt, const HD_VOID *Ptr, int Len);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_SocketSetBuf(HD_SOCKET Skt, HD_ULONG Size);
HDRIVE_EXTERN HD_LONG             HDRIVE_EXPORT HD_SocketWrite(HD_SOCKET Skt, const HD_VOID *Ptr, HD_LONG Len);

HDRIVE_EXTERN HD_ULONG            HDRIVE_EXPORT HD_TcpIpGetIPV4(HD_STRING HostName);
HDRIVE_EXTERN HD_ULONG            HDRIVE_EXPORT HD_TcpIpGetIPV4C(const HD_CHAR *HostName);
HDRIVE_EXTERN HD_ULONG            HDRIVE_EXPORT HD_TcpIpGetIPV4CW(const HD_WCHAR *HostName);
HDRIVE_EXTERN HD_ULONG            HDRIVE_EXPORT HD_TcpIpGetIPV4W(HD_WSTRING HostName);
HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_TcpIpOnLine(HD_VOID);

HDRIVE_EXTERN HD_BOOL             HDRIVE_EXPORT HD_WolSend(HD_MACADDR *Mac);

#  ifdef __cplusplus
   }
#  endif


/**** C++ wrapper ****/

#  ifdef __cplusplus

/**** String class ****/

class HDC_HttpClient
{
  public:

        /**** Methods ****/

        inline                          HDC_HttpClient(HD_VOID)                 { hClient = HD_HttpClientNew(); }
        inline                          ~HDC_HttpClient(HD_VOID)                { HD_HttpClientFree(hClient); }

        /**** Properties ****/

        inline HD_BOOL                  AddCookie(const HD_CHAR *Name, const HD_CHAR *Val, const HD_CHAR *Path, const HD_CHAR *Domain, const HD_CHAR *Expires) {
                                                                                  return HD_HttpClientAddCookie(hClient, Name, Val, Path, Domain, Expires);
                                                                                }
        inline HD_BOOL                  AddCookie(HDC_String Name, HDC_String Val, HDC_String Path, HDC_String Domain, HDC_String Expires) {
                                                                                  return HD_HttpClientAddCookie(hClient, Name.Cstr(), Val.Cstr(), Path.Cstr(), Domain.Cstr(), Expires.Cstr());
                                                                                }
        inline HD_BOOL                  AddCookieFile(const HD_CHAR *FileName, const HD_CHAR *Name, const HD_CHAR *Path, const HD_CHAR *Domain, const HD_CHAR *Expires) {
                                                                                  return HD_HttpClientAddCookieFile(hClient, FileName, Name, Path, Domain, Expires);
                                                                                }
        inline HD_BOOL                  AddCookieFile(HDC_String FileName, HDC_String Name, HDC_String Path, HDC_String Domain, HDC_String Expires) {
                                                                                  return HD_HttpClientAddCookieFile(hClient, FileName.Cstr(), Name.Cstr(), Path.Cstr(), Domain.Cstr(), Expires.Cstr());
                                                                                }
        inline HD_BOOL                  AddField(const HD_CHAR *Name, const HD_CHAR *Val) {
                                                                                  return HD_HttpClientAddField(hClient, Name, Val);
                                                                                }
        inline HD_BOOL                  AddField(const HD_CHAR *Name, HD_DOUBLE Val) {
                                                                                  return HD_HttpClientAddField(hClient, Name, HDC_String(Val).Cstr());
                                                                                }
        inline HD_BOOL                  AddField(const HD_CHAR *Name, HD_FLOAT Val) {
                                                                                  return HD_HttpClientAddField(hClient, Name, HDC_String(Val).Cstr());
                                                                                }
        inline HD_BOOL                  AddField(const HD_CHAR *Name, HD_LONG Val) {
                                                                                  return HD_HttpClientAddField(hClient, Name, HDC_String(Val).Cstr());
                                                                                }
        inline HD_BOOL                  AddField(const HD_CHAR *Name, HD_STRING Val) {
                                                                                  if (!Val) return FALSE;
                                                                                  return HD_HttpClientAddField(hClient, Name, Val -> Cstr);
                                                                                }
        inline HD_BOOL                  AddField(const HD_CHAR *Name, HD_ULONG Val) {
                                                                                  return HD_HttpClientAddField(hClient, Name, HDC_String(Val).Cstr());
                                                                                }
        inline HD_BOOL                  AddField(const HD_CHAR *Name, HDC_String Val) {
                                                                                  return HD_HttpClientAddField(hClient, Name, Val.Cstr());
                                                                                }
        inline HD_BOOL                  AddFile(const HD_CHAR *FileName, const HD_CHAR *Name, const HD_CHAR *PostFileName) {
                                                                                  return HD_HttpClientAddFile(hClient, FileName, Name, PostFileName);
                                                                                }
        inline HD_BOOL                  AddMem(const HD_CHAR *Name, const HD_CHAR *PostFileName, const HD_VOID *MemPtr, HD_ULONG Len) {
                                                                                  return HD_HttpClientAddMem(hClient, Name, PostFileName, MemPtr, Len);
                                                                                }
        inline HD_STRING                GetAgent(HD_VOID)                       { return hClient -> Agent;       }
        inline HD_HTTPCLIENT_GET        GetCallBack(HD_VOID)                    { return hClient -> GetCallBack; }
        inline HD_VOID *                GetCallBackArg(HD_VOID)                 { return (HD_VOID *)hClient -> GetCallBack; }
        inline HD_LONG                  GetHttpErrCode(HD_VOID)                 { return hClient -> ErrCode;     }
        inline HD_STRING                GetHost(HD_VOID)                        { return hClient -> Host;        }
        inline HD_STRING                GetPassword(HD_VOID)                    { return hClient -> Password;    }
        inline HD_LONG                  GetTransferEnc(HD_VOID)                 { return hClient -> TransferEnc; }
        inline HD_STRING                GetUri(HD_VOID)                         { return hClient -> Uri;         }
        inline HD_STRING                GetUserName(HD_VOID)                    { return hClient -> UserName;    }
        inline HD_VOID                  HttpGetFile(const HD_CHAR *FileName)    { if (!HD_HttpClientGetFileC(hClient, FileName))
                                                                                    throw hClient -> ErrCode;
                                                                                }
        inline HD_VOID                  HttpGetFile(HD_STRING FileName)         { if (!HD_HttpClientGetFile(hClient, FileName))
                                                                                    throw hClient -> ErrCode;
                                                                                }
        inline HD_VOID                  HttpGetFile(HDC_String FileName)        { if (!HD_HttpClientGetFile(hClient, FileName.Hdstr()))
                                                                                    throw hClient -> ErrCode;
                                                                                }
        HD_VOID *           HD_FASTCALL HttpGetMem(HD_ULONG *Size)              { HD_VOID *Ptr = HD_HttpClientGetMem(hClient, Size);
                                                                                  if (!Ptr) throw hClient -> ErrCode;
                                                                                  return Ptr;
                                                                                }
        HDC_String          HD_FASTCALL HttpGetStr(HD_VOID)                     { HD_ULONG Size;
                                                                                  HD_CHAR *Ptr = (HD_CHAR *)HD_HttpClientGetMem(hClient, &Size);
                                                                                  if (!Ptr) throw hClient -> ErrCode;
                                                                                  HDC_String Str;
                                                                                  Str.SetLen(Size);
                                                                                  HD_MemCpy(Str.Cstr(), Ptr, Size);
                                                                                  Str.Cstr()[Size] = 0;
                                                                                  HD_Free(Ptr);
                                                                                  return Str;
                                                                                }
        HDC_String          HD_FASTCALL HttpPostStr(HD_VOID)                    { HD_ULONG Size;
                                                                                  HD_CHAR *Ptr = (HD_CHAR *)HD_HttpClientPostMem(hClient, &Size);
                                                                                  if (!Ptr) throw hClient -> ErrCode;
                                                                                  HDC_String Str;
                                                                                  Str.SetLen(Size);
                                                                                  HD_MemCpy(Str.Cstr(), Ptr, Size);
                                                                                  Str.Cstr()[Size] = 0;
                                                                                  HD_Free(Ptr);
                                                                                  return Str;
                                                                                }
        inline void                     SetCallBack(HD_HTTPCLIENT_GET Func, HD_VOID *Arg) {
                                                                                  hClient -> GetCallBack    = Func;
                                                                                  hClient -> GetCallBackArg = Arg;
                                                                                }
        inline HD_VOID                  SetFlags(HD_LONG Flags)                 { HD_HttpClientSetFlags(hClient, Flags); }
#    ifdef VCL_H
        inline HD_BOOL                  SetUrl(AnsiString Url)                  { return HD_HttpClientParseUrlC(hClient, Url.c_str()); }
#    endif
        inline HD_BOOL                  SetUrl(const HD_CHAR *Url)              { return HD_HttpClientParseUrlC(hClient, Url); }
        inline HD_BOOL                  SetUrl(HD_STRING Url)                   { return HD_HttpClientParseUrl(hClient, Url); }
        inline HD_BOOL                  SetUrl(HDC_String &Url)                 { return HD_HttpClientParseUrl(hClient, Url.Hdstr()); }

        /**** Private properties ****/

  private:
        HD_HTTPCLIENT                   hClient;
};
  #endif
#endif

