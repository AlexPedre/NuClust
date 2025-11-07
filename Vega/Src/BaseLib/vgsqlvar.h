
/*************************************************
****           VEGA - SQL constants           ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __VG_SQLVAR_H
#  define  __VG_SQLVAR_H

/**** Field lenghts ****/

#  define  VG_SQLLEN_MOLNAME            255

#  ifdef VG_SQLVARDEF

const HD_CHAR *         VgSqlMolListQuery  = "SELECT %cID%c, %cName%c FROM %cMolecules%c";
const HD_CHAR *         VgSqlMolQuery      = "SELECT * FROM %cMolecules%c";
const HD_CHAR *         VgSqlMolQueryFlt   = "SELECT * FROM %cMolecules%c WHERE %cID%c = %lu";
const HD_CHAR *         VgSqlSmilesQuery   = "SELECT %cSmiles%c FROM %cMolecules%c WHERE %cID%c = %lu";

const HD_CHAR *         VgSqlColStructure  = "Structure";
const HD_CHAR *         VgSqlDbStruct3D    = "Struct3D";
const HD_CHAR *         VgSqlFldDate       = "Date";
const HD_CHAR *         VgSqlFldGroup      = "Group";
const HD_CHAR *         VgSqlFldID         = "ID";
const HD_CHAR *         VgSqlFldMolName    = "Name";
const HD_CHAR *         VgSqlFldTime       = "Time";
const HD_CHAR *         VgSqlFldVegaKey    = "Key";
const HD_CHAR *         VgSqlFldVegaValue  = "Value";
const HD_CHAR *         VgSqlTabGroups     = "Groups";
const HD_CHAR *         VgSqlTabMolecules  = "Molecules";
const HD_CHAR *         VgSqlTabStructures = "Structures";
const HD_CHAR *         VgSqlTabVega       = "Vega";
const HD_CHAR *         VgSqlValNull       = "NULL";

#  else

extern const HD_CHAR    *VgSqlMolListQuery;
extern const HD_CHAR    *VgSqlMolQuery, *VgSqlMolQueryFlt, *VgSqlSmilesQuery;

extern const HD_CHAR    *VgSqlColStructure, *VgSqlDbStruct3D;
extern const HD_CHAR    *VgSqlFldDate, *VgSqlFldGroup, *VgSqlFldID, *VgSqlFldMolName;
extern const HD_CHAR    *VgSqlFldTime, *VgSqlFldVegaKey;
extern const HD_CHAR    *VgSqlFldVegaValue, *VgSqlTabGroups, *VgSqlTabMolecules, *VgSqlTabStructures;
extern const HD_CHAR    *VgSqlTabVega, *VgSqlValNull;

#  endif
#endif

