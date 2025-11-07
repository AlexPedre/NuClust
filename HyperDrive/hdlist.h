
/*******************************************
****     HyperDrive - List routines     ****
**** (c) 2004-2025, Alessandro Pedretti ****
*******************************************/


#ifndef __HDLIST_H
#  define  __HDLIST_H

#  include <hyperdrive.h>

/**** Add leading underscores to exported functions ****/

#  ifdef HD_USE_LEADING_UNDERSCORE
#    define  HD_ListAppend              _HD_ListAppend
#    define  HD_ListBsearch             _HD_ListBsearch
#    define  HD_ListClear               _HD_ListClear
#    define  HD_ListCopyItem            _HD_ListCopyItem
#    define  HD_ListGet                 _HD_ListGet
#    define  HD_ListGetIndex            _HD_ListGetIndex
#    define  HD_ListJoin                _HD_ListJoin
#    define  HD_ListLinkAt              _HD_ListLinkAt
#    define  HD_ListLinkAtEnd           _HD_ListLinkAtEnd
#    define  HD_ListMerge               _HD_ListMerge
#    define  HD_ListMove                _HD_ListMove
#    define  HD_ListMoveEnd             _HD_ListMoveEnd
#    define  HD_ListNew                 _HD_ListNew
#    define  HD_ListRemove              _HD_ListRemove
#    define  HD_ListReSort              _HD_ListReSort
#    define  HD_ListSort                _HD_ListSort
#    define  HD_ListUnlink              _HD_ListUnlink
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
   extern "C" {
#  endif

HDRIVE_EXTERN HD_LISTITEM *     HDRIVE_EXPORT HD_ListAppend(HD_LIST *Lh);
HDRIVE_EXTERN HD_LISTITEM *     HDRIVE_EXPORT HD_ListBsearch(HD_LIST *Lh, HD_VOID *Key, HD_SORTCALLBACK Fcmp);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_ListClear(HD_LIST *Lh);
HDRIVE_EXTERN HD_LISTITEM *     HDRIVE_EXPORT HD_ListCopyItem(HD_LIST *Lh, HD_LISTITEM *Li);
HDRIVE_EXTERN HD_LISTITEM *     HDRIVE_EXPORT HD_ListGet(HD_LIST *Lh, HD_ULONG Idx);
HDRIVE_EXTERN HD_ULONG          HDRIVE_EXPORT HD_ListGetIndex(HD_LIST *Lh, HD_LISTITEM *Li);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_ListJoin(HD_LIST *DestList, HD_LIST *SrcList);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_ListLinkAt(HD_LIST *Lh, HD_LISTITEM *Li, HD_LISTITEM *LiPos);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_ListLinkAtEnd(HD_LIST *Lh, HD_LISTITEM *Li);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_ListMerge(HD_LIST *Dest, HD_LIST *Lh);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_ListMove(HD_LIST *Lh, HD_LISTITEM *Li, HD_ULONG NewPos);
HDRIVE_EXTERN HD_LIST *         HDRIVE_EXPORT HD_ListNew(HD_ULONG ItemSize);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_ListRemove(HD_LIST *Lh, HD_LISTITEM *Li);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_ListReSort(HD_LIST *Lh, HD_LISTITEM *Li, HD_SORTCALLBACK Fcmp);
HDRIVE_EXTERN HD_BOOL           HDRIVE_EXPORT HD_ListSort(HD_LIST *Lh, HD_SORTCALLBACK Fcmp);
HDRIVE_EXTERN HD_VOID           HDRIVE_EXPORT HD_ListUnlink(HD_LIST *Lh, HD_LISTITEM *Li);

#  ifdef __cplusplus
   }
#  endif

/**** C++ wrapper ****/

#  ifdef __cplusplus

template <class T> class HDC_ListIterator;

/**** List class ****/

template <class T> class HDC_List
{
friend class HDC_ListIterator <T>;

public:

        typedef struct __hdc_data {
           struct __hdc_data *          Next;
           struct __hdc_data *          Prev;
           T *                          Data;
        } HDC_DATA;

                        HDC_List(HD_VOID) {
                          List = HD_ListNew(sizeof(HDC_DATA));
                          if (!List) throw HD_ERR_OUTOFMEM;
                        }
                        ~HDC_List(HD_VOID) {
                          ClearInt();
                          HD_ListClear(List);
                        }
        T *             Add(HD_VOID) {
                          T *Data = new T;
                          HDC_DATA *Item = (HDC_DATA *)HD_ListAppend(List);
                          if (!Item) throw HD_ERR_OUTOFMEM;
                          Item -> Data = Data;
                          return Data;
                        }
        HD_VOID         Clear(HD_VOID) {
                          if (!List) return;
                          ClearInt();
                          List -> Beg  = HD_NULL;
                          List -> Last = HD_NULL;
                          List -> Num  = 0;
                        }
        HD_ULONG        Count(HD_VOID) { return List -> Num; }
        T *             First(HD_VOID) {
                          if (!List -> Beg) return HD_NULL;
//                          return ((HDC_List<T>::HDC_DATA *)List -> Beg) -> Data;
                          return ((HDC_DATA *)List -> Beg) -> Data;
                        }
        T *             Get(HD_ULONG i) {
                          HDC_DATA *Item = (HDC_DATA *)HD_ListGet(List, i);
                          if (!Item) return HD_NULL;
                          return Item -> Data;
                        }
        HD_LISTITEM *   GetItem(HD_ULONG i) { return HD_ListGet(List, i); }
        HD_BOOL         IsEmpty(HD_VOID) { return (List -> Beg == HD_NULL); }
        HD_BOOL         Join(HD_LIST *SrcList) { return HD_ListJoin(List, SrcList); }
        T *             Last(HD_VOID) {
                          if (!List -> Beg) return HD_NULL;
//                          return ((HDC_List<T>::HDC_DATA *)List -> Last) -> Data;
                          return ((HDC_DATA *)List -> Last) -> Data;
                        }
        HD_VOID         Move(HD_LISTITEM *Li, HD_ULONG NewPos) { HD_ListMove(List, Li, NewPos); }
        HD_VOID         Remove(HD_LISTITEM *Li) { HD_ListRemove(List, Li); }
        HD_VOID         ReSort(HD_LISTITEM *Li, HD_SORTCALLBACK Fcmp) { HD_ListReSort(List, Li, Fcmp); }
        HD_VOID         Sort(HD_SORTCALLBACK Fcmp) { HD_ListSort(List, Fcmp); }
        HD_VOID         Unlink(HD_LISTITEM *Li) { HD_ListUnlink(List, Li); }

private:
        HD_LIST *       List;

        HD_VOID         ClearInt(HD_VOID) {
                          for(HDC_DATA *Ptr = (HDC_DATA *)List -> Beg; Ptr; Ptr = Ptr -> Next)
                            delete Ptr -> Data;
                        }
};

/**** List iterator ****/

template <class T> class HDC_ListIterator
{

public:

        /**** Constructors ****/

                        HDC_ListIterator(HDC_List <T> &l) {
                          IterList    = &l;
                          IterCurrent = HD_NULL;
                        }

                        HDC_ListIterator(HDC_List <T> *l) {
                          IterList    = l;
                          IterCurrent = HD_NULL;
                        }

        /**** Get the current list item ****/

        HD_LISTITEM *   CurrentItem(HD_VOID) {
                          if (!IterCurrent) return HD_NULL;
                          else return (HD_LISTITEM *)IterCurrent;
                        }

        /**** Get the current item ****/

        T *             Current(HD_VOID) {
                          if (!IterCurrent) return HD_NULL;
                          else return IterCurrent -> Data;
                        }

        /**** Get the next item ****/

        T *             Next(HD_VOID) {
                          if (IterList -> IsEmpty()) return HD_NULL;
                          if (!IterCurrent) {
                            IterCurrent = (HD_TMCCAST HDC_List<T>::__hdc_data *)IterList -> List -> Beg;
                            return IterList -> First();
                          } else {
                            IterCurrent = IterCurrent -> Next;
                            if (IterCurrent) return IterCurrent -> Data;
                            return HD_NULL;
                          }
                        }

        /**** Get the previous item ****/

        T *             Prev(HD_VOID) {
                          if (!IterList -> Count()) return HD_NULL;
                          if (!IterCurrent) {
                            IterCurrent = (HD_TMCCAST HDC_List<T>::__hdc_data *)IterList -> List -> Last;
                            return IterList -> Last();
                          } else {
                             IterCurrent = IterCurrent -> Prev;
                             if (IterCurrent) return IterCurrent -> Data;
                             return HD_NULL;
                          }
                        }

        /**** Rewind the iterator ****/

        HD_VOID            Rewind(HD_VOID) {IterCurrent = HD_NULL; }

        /**** Go to the end ****/

        HD_VOID            Forward(HD_VOID) {IterCurrent = HD_NULL; }

private:
        HDC_List<T> *                           IterList;
        HD_TMCCAST HDC_List<T>::__hdc_data *    IterCurrent;
};

#  endif
#endif
