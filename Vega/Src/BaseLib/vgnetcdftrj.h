
/*************************************************
****      VEGA - NetCDF trajectory file       ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __VG_NETCDFTRJ_H
#  define  __VG_NETCDFTRJ_H

#  ifdef WIN32
#    ifdef WIN64
#      include <nik-long64bit.h>
#    else
#      include <nik-long32bit.h>
#    endif
#  else
#    define  niklongmy        long
#    define  niklonglongmy    long long
#  endif

#include <netcdf.h>

/**** NetCdfCreate() flags ****/

#  define  VG_NETCDF_CRTFLG_NONE            0  /* None                      */
#  define  VG_NETCDF_CRTFLG_BOX             1  /* Write cell/box            */
#  define  VG_NETCDF_CRTFLG_COMP            2  /* Compressed coordinates    */
#  define  VG_NETCDF_CRTFLG_COORD           4  /* Write coordinates         */
#  define  VG_NETCDF_CRTFLG_FORCE           8  /* Write forces              */
#  define  VG_NETCDF_CRTFLG_REMCRDIDX      16  /* Replica coord. index      */
#  define  VG_NETCDF_CRTFLG_REMINDEX       32  /* Replica index             */
#  define  VG_NETCDF_CRTFLG_REMTEMP        64  /* Replica temperature       */
#  define  VG_NETCDF_CRTFLG_REMVALUE      128  /* Replica values            */
#  define  VG_NETCDF_CRTFLG_TIME          256  /* Write time data           */
#  define  VG_NETCDF_CRTFLG_VEL           512  /* Write velocities          */

#  define  VG_NETCDF_CRTFLG_ALL    0xffffffff  /* All flags                 */

/**** File formats ****/

#  define  VG_NETCDF_FORMAT_UNK             0  /* Unknown file format       */
#  define  VG_NETCDF_FORMAT_V3              1  /* NetCDF V3 (classic)       */
#  define  VG_NETCDF_FORMAT_V4              2  /* NetCDF V4 (really HDF5)   */

/**** File types (Don't change the order !) ****/

#  define  VG_NETCDF_TYPE_UNKNOWN           0  /* Unknown type              */
#  define  VG_NETCDF_TYPE_ENSEMBLE          1  /* Amber ensemble trajectory */
#  define  VG_NETCDF_TYPE_RESTART           2  /* Amber restart             */
#  define  VG_NETCDF_TYPE_TRAJ              3  /* Amber trajectory          */

/**** Variable names ****/

#  define  VG_NETCDF_VAR_ATOM               "atom"
#  define  VG_NETCDF_VAR_BINS               "bins"
#  define  VG_NETCDF_VAR_CELL_ANGLES        "cell_angles"
#  define  VG_NETCDF_VAR_CELL_ANGULAR       "cell_angular"
#  define  VG_NETCDF_VAR_CELL_LENGTHS       "cell_lengths"
#  define  VG_NETCDF_VAR_CELL_SPATIAL       "cell_spatial"
#  define  VG_NETCDF_VAR_COMPFRC            "compressedfrc"
#  define  VG_NETCDF_VAR_COMPPOS            "compressedpos"
#  define  VG_NETCDF_VAR_COMPVEL            "compressedvel"
#  define  VG_NETCDF_VAR_CONVENTIONS        "Conventions"
#  define  VG_NETCDF_VAR_CONVVER            "ConventionVersion"
#  define  VG_NETCDF_VAR_COORDS             "coordinates"
#  define  VG_NETCDF_VAR_ENSEMBLE           "ensemble"
#  define  VG_NETCDF_VAR_EPTOT              "eptot"
#  define  VG_NETCDF_VAR_FRAME              "frame"
#  define  VG_NETCDF_VAR_FRC                "forces"
#  define  VG_NETCDF_VAR_ICOMPFAC           "icompressfac"
#  define  VG_NETCDF_VAR_LABEL              "label"
#  define  VG_NETCDF_VAR_LABELLEN           5
#  define  VG_NETCDF_VAR_REMD_CRDIDX        "remd_crdidx"
#  define  VG_NETCDF_VAR_REMD_DIMENSION     "remd_dimension"
#  define  VG_NETCDF_VAR_REMD_DIMTYPE       "remd_dimtype"
#  define  VG_NETCDF_VAR_REMD_INDICES       "remd_indices"
#  define  VG_NETCDF_VAR_REMD_REPIDX        "remd_repidx"
#  define  VG_NETCDF_VAR_REMD_VALUES        "remd_values"
#  define  VG_NETCDF_VAR_SPATIAL            "spatial"
#  define  VG_NETCDF_VAR_TEMPERATURE        "temp0"
#  define  VG_NETCDF_VAR_TIME               "time"
#  define  VG_NETCDF_VAR_VELO               "velocities"

/**** Constants ****/

#  define  VG_NETCDF_AMBERTIME_TO_PS        20.455

#  ifdef WIN64
#    define  VG_NETCDF_SIZE       HD_UDLONG
#  else
#    define  VG_NETCDF_SIZE       size_t
#  endif

/**** Amber NC dimension IDs ****/

typedef struct {
  HD_LONG                   Atom;
  HD_LONG                   CellAngular;
  HD_LONG                   CellSpatial;
  HD_LONG                   Ensamble;
  HD_LONG                   Frame;
  HD_LONG                   Label;
  HD_LONG                   RemdDimension;
  HD_LONG                   Spatial;
} VG_AMBERNC_DIMID;

/**** Amber NC variable IDs ****/

typedef struct {
  HD_LONG                   CellAngles;
  HD_LONG                   CellAngular;
  HD_LONG                   CellLenghts;
  HD_LONG                   CellSpatial;
  HD_LONG                   CompressedFrc;
  HD_LONG                   CompressedPos;
  HD_LONG                   CompressedVel;
  HD_LONG                   Coordinates;
  HD_LONG                   Forces;
  HD_LONG                   Indices;
  HD_LONG                   RemdCrdIdx;
  HD_LONG                   RemdDimType;
  HD_LONG                   RemdIndices;
  HD_LONG                   RemdValues;
  HD_LONG                   Spatial;
  HD_LONG                   Temperature;
  HD_LONG                   Time;
  HD_LONG                   Velocities;
} VG_AMBERNC_VARID;

/**** Amber NC context ****/

typedef struct {
  HD_FLOAT *                Buffer;
  HD_LONG                   hNet;
  HD_LONG                   Type;
  VG_AMBERNC_DIMID          DimId;
  VG_NETCDF_SIZE            Atom;
  VG_NETCDF_SIZE            CellAngular;
  VG_NETCDF_SIZE            CellSpatial;
  VG_NETCDF_SIZE            CurFrame;
  VG_NETCDF_SIZE            Frame;
  VG_NETCDF_SIZE            Label;
  VG_NETCDF_SIZE            Spatial;
  VG_AMBERNC_VARID          VarId;
} VG_AMBERNC;

typedef enum  {
  V_COORDS = 0, V_VEL,  V_FRC, V_TEMP, V_BOXL,
  V_BOXA,       V_TIME, V_IND, V_RIDX, V_CIDX,
  V_REMDVALS,
  NVID
} VG_NETCDF_VIDTYPE;

/**** Library definitions ****/

#  if defined(LINUX) || defined(WIN32)
#    ifdef LINUX
#      define  VG_NETCDF_DLL                "libnetcdf.so"
#      define  VG_WINAPI
#    else
#      define  VG_NETCDF_DLL                "libnetcdf-7.dll"
#      define  VG_WINAPI                    _cdecl
#    endif

#    ifdef VG_NETCDF_DYNDLL
#      define  VG_NETCDF_EXTERN
#    else
#      ifdef __cplusplus
#        define  VG_NETCDF_EXTERN           extern "C"
#      else
#        define  VG_NETCDF_EXTERN           extern
#      endif
#    endif

/**** NetCDF functions ****/

VG_NETCDF_EXTERN HD_LONG        (VG_WINAPI *VG_nc_close)(HD_LONG);
VG_NETCDF_EXTERN HD_LONG        (VG_WINAPI *VG_nc_create)(const HD_CHAR *, HD_LONG, HD_LONG *);
VG_NETCDF_EXTERN HD_LONG        (VG_WINAPI *VG_nc_def_dim)(HD_LONG, const HD_CHAR *, VG_NETCDF_SIZE, HD_LONG *);
VG_NETCDF_EXTERN HD_LONG        (VG_WINAPI *VG_nc_def_var)(HD_LONG, const HD_CHAR *, nc_type, HD_LONG, HD_LONG *, HD_LONG *);
VG_NETCDF_EXTERN HD_LONG        (VG_WINAPI *VG_nc_def_var_chunking)(HD_LONG, HD_LONG, HD_LONG, const VG_NETCDF_SIZE *);
VG_NETCDF_EXTERN HD_LONG        (VG_WINAPI *VG_nc_def_var_deflate)(HD_LONG, HD_LONG, HD_LONG, HD_LONG, HD_LONG deflate_level);
VG_NETCDF_EXTERN HD_LONG        (VG_WINAPI *VG_nc_enddef)(HD_LONG);
VG_NETCDF_EXTERN HD_LONG        (VG_WINAPI *VG_nc_inq_attlen)(HD_LONG, HD_LONG, const HD_CHAR *, VG_NETCDF_SIZE *);
VG_NETCDF_EXTERN HD_LONG        (VG_WINAPI *VG_nc_get_att_text)(HD_LONG, HD_LONG, const HD_CHAR *, HD_CHAR *);
VG_NETCDF_EXTERN HD_LONG        (VG_WINAPI *VG_nc_get_vara_float)(HD_LONG, HD_LONG, const VG_NETCDF_SIZE *, const VG_NETCDF_SIZE *, HD_FLOAT *);
VG_NETCDF_EXTERN HD_LONG        (VG_WINAPI *VG_nc_inq_atttype)(HD_LONG, HD_LONG, const HD_CHAR *, nc_type *);
VG_NETCDF_EXTERN HD_LONG        (VG_WINAPI *VG_nc_inq_dimid)(HD_LONG, const HD_CHAR *, HD_LONG *);
VG_NETCDF_EXTERN HD_LONG        (VG_WINAPI *VG_nc_inq_dimlen)(HD_LONG, HD_LONG, VG_NETCDF_SIZE *lenp);
VG_NETCDF_EXTERN HD_LONG        (VG_WINAPI *VG_nc_inq_var)(HD_LONG, HD_LONG, HD_CHAR *, nc_type *, HD_LONG *, HD_LONG *, HD_LONG *);
VG_NETCDF_EXTERN HD_LONG        (VG_WINAPI *VG_nc_inq_var_chunking)(HD_LONG, HD_LONG, HD_LONG *, VG_NETCDF_SIZE *);
VG_NETCDF_EXTERN HD_LONG        (VG_WINAPI *VG_nc_inq_varid)(HD_LONG, const HD_CHAR *name, HD_LONG *);
VG_NETCDF_EXTERN HD_LONG        (VG_WINAPI *VG_nc_inq_varndims)(HD_LONG, HD_LONG, HD_LONG *);
VG_NETCDF_EXTERN HD_LONG        (VG_WINAPI *VG_nc_open)(const HD_CHAR *, HD_LONG, HD_LONG *);
VG_NETCDF_EXTERN HD_LONG        (VG_WINAPI *VG_nc_put_att_double)(HD_LONG, HD_LONG, const char *HD_CHAR, nc_type, VG_NETCDF_SIZE, const HD_DOUBLE *);
VG_NETCDF_EXTERN HD_LONG        (VG_WINAPI *VG_nc_put_att_float)(HD_LONG, HD_LONG, const HD_CHAR *, nc_type, VG_NETCDF_SIZE, const HD_FLOAT *);
VG_NETCDF_EXTERN HD_LONG        (VG_WINAPI *VG_nc_put_att_text)(HD_LONG, HD_LONG, const HD_CHAR *, VG_NETCDF_SIZE, const HD_CHAR *);
VG_NETCDF_EXTERN HD_LONG        (VG_WINAPI *VG_nc_put_vara_float)(HD_LONG, HD_LONG, const VG_NETCDF_SIZE *, const VG_NETCDF_SIZE *, const HD_FLOAT *);
VG_NETCDF_EXTERN HD_LONG        (VG_WINAPI *VG_nc_put_vara_text)(HD_LONG, HD_LONG, const VG_NETCDF_SIZE *, const VG_NETCDF_SIZE *, const HD_CHAR *op);
VG_NETCDF_EXTERN HD_LONG        (VG_WINAPI *VG_nc_set_fill)(HD_LONG, HD_LONG, HD_LONG *);
VG_NETCDF_EXTERN HD_LONG        (VG_WINAPI *VG_nc_sync)(HD_LONG);

#  else

#    define  VG_nc_close                        nc_close
#    define  VG_nc_create                       nc_create
#    define  VG_nc_def_dim                      nc_def_dim
#    define  VG_nc_def_var                      nc_def_var
#    define  VG_nc_def_var_chunking             nc_def_var_chunking
#    define  VG_nc_def_var_deflate              nc_def_var_deflate
#    define  VG_nc_enddef                       nc_enddef
#    define  VG_nc_inq_attlen                   nc_inq_attlen
#    define  VG_nc_get_att_text                 nc_get_att_text
#    define  VG_nc_get_vara_float               nc_get_vara_float
#    define  VG_nc_inq_atttype                  nc_inq_atttype
#    define  VG_nc_inq_dimid                    nc_inq_dimid
#    define  VG_nc_inq_dimlen                   nc_inq_dimlen
#    define  VG_nc_inq_var                      nc_inq_var
#    define  VG_nc_inq_var_chunking             nc_inq_var_chunking
#    define  VG_nc_inq_varid                    nc_inq_varid
#    define  VG_nc_inq_varndims                 nc_inq_varndims
#    define  VG_nc_open                         nc_open
#    define  VG_nc_put_att_double               nc_put_att_double
#    define  VG_nc_put_att_float                nc_put_att_float
#    define  VG_nc_put_att_text                 nc_put_att_text
#    define  VG_nc_put_vara_float               nc_put_vara_float
#    define  VG_nc_put_vara_text                nc_put_vara_text
#    define  VG_nc_set_fill                     nc_set_fill
#    define  VG_nc_sync                         nc_sync
#  endif

/**** Add leading underscores to exported functions ****/

#  ifdef VG_USE_LEADING_UNDERSCORE
#    define  VG_NetCdfClose                     _VG_NetCdfClose
#    define  VG_NetCdfCreate                    _VG_NetCdfCreate
#    define  VG_NetCdfOpen                      _VG_NetCdfOpen
#    define  VG_NetCdfReadFrm                   _VG_NetCdfReadFrm
#    define  VG_NetCdfWriteFrm                  _VG_NetCdfWriteFrm
#  endif

/**** Prototypes ****/

#  ifdef __cplusplus
extern "C" {
#  endif

VEGA_EXTERN HD_VOID       VEGA_EXPORT VG_NetCdfClose(VG_AMBERNC *hAmber);
VEGA_EXTERN HD_BOOL       VEGA_EXPORT VG_NetCdfCreate(const HD_CHAR *FileName, HD_LONG Format, HD_LONG Type, HD_ULONG NumAtm, HD_ULONG EnsembleSize,
                                                      HD_LONG RemdDimension, HD_LONG Flags);
VEGA_EXTERN VG_AMBERNC *  VEGA_EXPORT VG_NetCdfOpen(const HD_CHAR *FileName, HD_BOOL Write);
VEGA_EXTERN HD_BOOL       VEGA_EXPORT VG_NetCdfReadFrm(VG_AMBERNC *hAmber, HD_ATOM *InizAtm, HD_BOOL ActiveOnly);
VEGA_EXTERN HD_BOOL       VEGA_EXPORT VG_NetCdfWriteFrm(VG_AMBERNC *hAmber, HD_ATOM *InizAtm, HD_BOOL ActiveOnly);

#  ifdef __cplusplus
}
#  endif
#endif
