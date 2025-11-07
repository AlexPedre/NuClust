
/*************************************************
****          VEGA - Command errors           ****
**** Copyright 1996-2025, Alessandro Pedretti ****
*************************************************/


#ifndef __VG_COMERR_H
#  define __VG_COMERR_H

/**** Return codes ****/

#  define  VG_PARET_OK                         0     /* No errors                       */
#  define  VG_PARET_MSG_PROC                   1     /* Message processed without err.  */

#  define  VG_PARET_ABORT                     11     /* Abort                           */
#  define  VG_PARET_LOCALE                    12     /* LocaleLib error                 */
#  define  VG_PARET_NOCOM                     13     /* No command                      */
#  define  VG_PARET_OUTOFMEM                  44     /* Out of memory                   */
#  define  VG_PARET_JAVANOTINST               45     /* Java not installed              */

/**** Input/Output ****/

#  define  VG_PARET_IOBZIP2                   51     /* Bzip2 error                     */
#  define  VG_PARET_IOCANTPACK                52     /* Can't pack the file             */
#  define  VG_PARET_IODOS                     53     /* DOS I/O error                   */
#  define  VG_PARET_IOGZIP                    54     /* Gzip error                      */
#  define  VG_PARET_IONOSTDOUT                55     /* Stdout not allowed              */
#  define  VG_PARET_IOPKSTDOUT                56     /* No stdout with packed output    */
#  define  VG_PARET_IOPOWERPK                 57     /* PowerPacker error               */
#  define  VG_PARET_IOPOWERPKCR               58     /* PowerPacker comp. AmigaOS only  */
#  define  VG_PARET_IOPOWERPKLIB              59     /* PowerPacker.library not found   */
#  define  VG_PARET_IOPOWERPSHORT             60     /* File too short                  */
#  define  VG_PARET_IOUNKPACK                 61     /* Unknown compressor              */
#  define  VG_PARET_IOVEGADIR                 62     /* Set the environment variable    */
#  define  VG_PARET_IOXPK                     63     /* xPK error                       */
#  define  VG_PARET_IOZ32                     64     /* Z32 error                       */
#  define  VG_PARET_IODOWNLOAD                65     /* Can't download the file         */
#  define  VG_PARET_IOHTTPINIT                66     /* Can't initialize the HTTP cli.  */
#  define  VG_PARET_IOPARSEURL                67     /* Can't parse the URL             */

#  define  VG_PARET_UNKCOM                   101     /* Unknown command                 */
#  define  VG_PARET_TOOARGS                  102     /* Too many arguments              */
#  define  VG_PARET_FEWARGS                  103     /* Too few arguments               */
#  define  VG_PARET_ILLARG                   104     /* Illegal type of argument        */
#  define  VG_PARET_EXCRANGE                 105     /* Value exceed the legal range    */
#  define  VG_PARET_UNKKEYWORD               106     /* Unknown keyword in argument     */

#  define  VG_PARET_NOTIMP                   201     /* Command not already implemented */
#  define  VG_PARET_OGLONLY                  202     /* Command for OpenGL only         */
#  define  VG_PARET_NOMOL                    203     /* No molecule                     */
#  define  VG_PARET_NOSRF                    204     /* No surface present              */
#  define  VG_PARET_NOTRJ                    205     /* No trajectory                   */

/**** Command line ****/

#  define  VG_PARET_AGPATMNUM                301     /* Total number of atoms exceeded  */
#  define  VG_PARET_AGPDUPDESC               302     /* Duplicate description           */
#  define  VG_PARET_AGPILLATN                303     /* Illegal atom number             */
#  define  VG_PARET_AGPILLNMES               304     /* Illegal number of atoms in meas */
#  define  VG_PARET_AGPINCDESC               305     /* Incorrect atom description      */
#  define  VG_PARET_AGPINPFILE               306     /* It don't match the input file   */
#  define  VG_PARET_AGPMATCH                 307     /* Description with multiple match */
#  define  VG_PARET_AGPTOOFEW                308     /* Too few atoms to measure        */
#  define  VG_PARET_AGPTOOLONG               309     /* Atom description too long       */
#  define  VG_PARET_AGPUNKMES                310     /* Unknown measure mode            */
#  define  VG_PARET_ARGPARFRMINV             311     /* Invalid frame number            */
#  define  VG_PARET_ARGPARFRMINVFIRST        312     /* First frame exceeds the total   */
#  define  VG_PARET_ARGPARFRMINVLAST         313     /* Last frame exceeds the total    */
#  define  VG_PARET_ARGPARFRMMIS             314     /* Missing first frame             */
#  define  VG_PARET_ARGPARFRMRNG             315     /* Invalid range of frames         */
#  define  VG_PARET_ARGCPUS                  316     /* Invalid number of CPUs          */
#  define  VG_PARET_ARGMEASTRJ               317     /* -m and trajectory format        */
#  define  VG_PARET_ARGINFOXML               318     /* Unknown keyword for InfoXML     */
#  define  VG_PARET_ARGCAPCTERM              319     /* Unknown keyword for C-term cap  */
#  define  VG_PARET_ARGCAPNTERM              320     /* Unknown keyword for N-term cap  */

/**** Load and save operations ****/

#  define  VG_PARET_MOLBIOSNS                401     /* Biosym subformat not supported  */
#  define  VG_PARET_MOLCOMFAFL               402     /* Field type not specified        */
#  define  VG_PARET_MOLCOMFARG               403     /* Sybyl rgn file not loaded       */
#  define  VG_PARET_MOLCONBORD               404     /* Unacceptable bond order         */
#  define  VG_PARET_MOLCONVDW                405     /* Unknown VDW radius              */
#  define  VG_PARET_MOLCRDASS                406     /* No associated molecule file     */
#  define  VG_PARET_MOLCRDMEAS               407     /* Type of measure not specified   */
#  define  VG_PARET_MOLCSSR                  408     /* CSSR/QMC format more than 9999  */
#  define  VG_PARET_MOLFASTA                 409     /* Input file isn't protein or DNA */
#  define  VG_PARET_MOLIFFCORR               410     /* Corrupted IFF file              */
#  define  VG_PARET_MOLIFFINV                411     /* Invalid IFF file                */
#  define  VG_PARET_MOLIFFNOT                412     /* Not an IFF XXXX file            */
#  define  VG_PARET_MOLMOL2CORR              413     /* Corrupted or incoplete Mol2     */
#  define  VG_PARET_MOLMOL2NOTF              414     /* Can't find TRIPOS template      */
#  define  VG_PARET_MOLMOL2TEMP              415     /* Illegal TRIPOS template         */
#  define  VG_PARET_MOLMSFFORMAT             416     /* The file isn't in MSF format    */
#  define  VG_PARET_MOLMSFNCOMP              417     /* The MSF file isn't compatible   */
#  define  VG_PARET_MOLMOPACATOM             418     /* Faulty atom                     */
#  define  VG_PARET_MOLMOPACBADCON           419     /* Bad cartesian to internal conv. */
#  define  VG_PARET_MOLNOCHARGE              420     /* The format don't support charge */
#  define  VG_PARET_MOLNOFFTAG               421     /* The format don't support ff tag */
#  define  VG_PARET_MOLNOTFOUND              422     /* Input file not found            */
#  define  VG_PARET_MOLRGNCORRUPT            423     /* Corrupted rgn file              */
#  define  VG_PARET_MOLRGNNOMOL              424     /* Region file without a molecule  */
#  define  VG_PARET_MOLRGNNUMSTPS            425     /* Illegal number of steps in rgn  */
#  define  VG_PARET_MOLRGNPOINTS             426     /* Illegal number of points in rgn */
#  define  VG_PARET_MOLRGNSTPSIZE            427     /* Illegal step size in rgn file   */
#  define  VG_PARET_MOLUNKINFOR              428     /* Unknown input format            */
#  define  VG_PARET_MOLUNKOUTFOR             429     /* Unknown output format           */
#  define  VG_PARET_SRFNOMOL                 430     /* No molecule loaded              */
#  define  VG_PARET_MOLIFFREAD               431     /* Unable to read the IFF file     */
#  define  VG_PARET_MOLIFFWRITE              432     /* Unable to write the IFF file    */
#  define  VG_PARET_MOLTYPE                  433     /* Unknown mol type to add hydrog. */
#  define  VG_PARET_MOLINFOXML               434     /* Nothin to calculate             */
#  define  VG_PARET_RMHYDROG                 435     /* Unknown remove hydrogen method  */
#  define  VG_PARET_TORTYPE                  436     /* Unknown torsion method          */
#  define  VG_PARET_DBEXMODE                 437     /* Unknown database extr. mode     */
#  define  VG_PARET_DBINVREC                 438     /* Invalid record number           */
#  define  VG_PARET_DBNOTFOUND               439     /* Record not found                */
#  define  VG_PARET_DBTOOMANY                440     /* Too many databases              */
#  define  VG_PARET_DBSQL                    441     /* Invalid SQL code                */
#  define  VG_PARET_R2DUNKFORMAT             442     /* Unsupported 2D file format      */
#  define  VG_PARET_WKSLOCKMOL               443     /* Workspace locked                */
#  define  VG_PARET_SPILLOMISLIG             444     /* Spillo missing ligand           */

/**** Merge ****/

#  define  VG_PARET_MERGEUNALLELEM           455     /* Not allowed merge               */
#  define  VG_PARET_MERGEUNCOMP              456     /* Incompatible molecules          */

/**** Plots ****/

#  define  VG_PARET_PLOTSAVER                461     /* With a trajectory only          */
#  define  VG_PARET_PLOTPOINTRANGE           462     /* Point out of range              */

/**** Solvatation ****/

#  define  VG_PARET_SOLCANTOPEN              471     /* Can't open shell file           */
#  define  VG_PARET_SOLNOTHING               472     /* Nothing to add                  */
#  define  VG_PARET_SOLSHELLDIM              473     /* Molecule exceeds the shell dim. */

/**** Trajectory analysis ****/

#  define  VG_PARET_DCDSELECT                481     /* Incorrect selection             */
#  define  VG_PARET_DCDUNCHARGED             482     /* Unassigned atomic charges       */
#  define  VG_PARET_DCDUNKTRAJ               483     /* Unknown trajectory file         */
#  define  VG_PARET_DCDUNSOUT                484     /* Unsupported output              */
#  define  VG_PARET_DCDNOMOL                 485     /* No molecule loaded              */
#  define  VG_PARET_DCDGRAPH                 486     /* Energy graph can't be showed    */
#  define  VG_PARET_DCDNOOUT                 487     /* Output file not specified       */
#  define  VG_PARET_DCDRMSDNOSRF             488     /* VG_Surface not permitted           */
#  define  VG_PARET_DCDRMSDNOTRAJ            489     /* Trajectory not permitted        */
#  define  VG_PARET_DCDRMSDUNCOMPM           490     /* Uncompatible molecules          */
#  define  VG_PARET_DCDSAMEFILE              491     /* Same trajectory file            */
#  define  VG_PARET_TRAJINVHANDLE            492     /* Invalid handle                  */
#  define  VG_PARET_DCDATMNUM                493     /* Mismatching number of atoms     */
#  define  VG_PARET_AUTODOCKCORR             494     /* Corrupted AutoDock output       */

/**** Charges ****/

#  define  VG_PARET_CHGNOTASS                501     /* Atomic charges not assigned     */
#  define  VG_PARET_CHGTEMATMLONG            502     /* Atom name too long in temp.     */
#  define  VG_PARET_CHGTEMATMMIS             503     /* Missing atom name in temp.      */
#  define  VG_PARET_CHGTEMBONDINV            504     /* Invalid number of bonds in temp.*/
#  define  VG_PARET_CHGTEMBONDMIS            505     /* Missing number of bonds in temp.*/
#  define  VG_PARET_CHGTEMCALLITS            506     /* A macro/residue can't call its. */
#  define  VG_PARET_CHGTEMDEL                507     /* Unable to delete atom in temp.  */
#  define  VG_PARET_CHGTEMDESCDUP            508     /* #Description duplicated in temp.*/
#  define  VG_PARET_CHGTEMDESCLONG           509     /* Decription too long in temp.    */
#  define  VG_PARET_CHGTEMFORMAT             510     /* Unknown format of charge temp.  */
#  define  VG_PARET_CHGTEMGRPINV             511     /* Invalid group ID in temp.       */
#  define  VG_PARET_CHGTEMGRPMIS             512     /* Missing group ID in temp.       */
#  define  VG_PARET_CHGTEMIDDUP              513     /* Duplicated ID in temp.          */
#  define  VG_PARET_CHGTEMIDLONG             514     /* ID too long in temp.            */
#  define  VG_PARET_CHGTEMIDMIS              515     /* Missing ID in temp.             */
#  define  VG_PARET_CHGTEMIDUNI              516     /* Non-unique ID in temp.          */
#  define  VG_PARET_CHGTEMIDUNK              517     /* Unknown ID in temp.             */
#  define  VG_PARET_CHGTEMRESEXP             518     /* #ResName expected in temp.      */
#  define  VG_PARET_CHGTEMRESLONG            519     /* Residue name too long in temp.  */
#  define  VG_PARET_CHGTEMRESMIS             520     /* Missing residue name in temp.   */

/**** Force field ****/

#  define  VG_PARET_FFATYTOOLG               550     /* Atom type too long              */
#  define  VG_PARET_FFCANTASS                551     /* Can't assign potential          */
#  define  VG_PARET_FFILLNUM                 552     /* Illegal number of arguments     */
#  define  VG_PARET_FFINCATM                 553     /* Incorrect atom description      */
#  define  VG_PARET_FFINCSATM                554     /* Incorrect subatom description   */
#  define  VG_PARET_FFNOTFOUND               555     /* Template file not found         */
#  define  VG_PARET_FFNOTSTD                 556     /* Template not in standard format */
#  define  VG_PARET_FFSUBLVL                 557     /* Sublevel overflow               */
#  define  VG_PARET_FFUNBPAR                 558     /* Unbalenced parenthesis          */
#  define  VG_PARET_FFILLAROM                559     /* Illegal aromaticity             */
#  define  VG_PARET_FFILLBONDORD             560     /* Illegal bond order              */
#  define  VG_PARET_FFILLRING                561     /* Illegal ring size               */
#  define  VG_PARET_FFINVELEM                562     /* Invalid element                 */
#  define  VG_PARET_FFINVOP                  563     /* Invalid operator                */
#  define  VG_PARET_FFMULTIOP                564     /* Multiple operators              */
#  define  VG_PARET_FFREQOP                  565     /* Operator required               */
#  define  VG_PARET_FFSMARTSFILE             566     /* Invalid SMARTS file             */
#  define  VG_PARET_FFSMARTSINV              567     /* Invalid SMARTS                  */

/**** Calculations ****/

#  define  VG_PARET_CALEFFNOTASS             601     /* Force field not assigned        */
#  define  VG_PARET_CALENNOBOND              602     /* Non-bond parameters not found   */
#  define  VG_PARET_CALENNOFF                603     /* Can't open template             */
#  define  VG_PARET_CALENRES                 604     /* More than one residue is needed */
#  define  VG_PARET_CALENRESNF               605     /* Residue not found               */
#  define  VG_PARET_CALENUNKTYP              606     /* Unknown atom type               */
#  define  VG_PARET_CALLOGPNOPAR             607     /* Not all atoms are parametrized  */
#  define  VG_PARET_CALLOGNOTF               608     /* Parameters not found            */
#  define  VG_PARET_CALLOGPUNREC             609     /* Unrecognized parameter file     */
#  define  VG_PARET_CALNOVLOGP               610     /* No Virtual logP calculation     */
#  define  VG_PARET_CALSRFILM                611     /* A water cluster required        */
#  define  VG_PARET_CALCLUSTTBIG             612     /* Too many cell copies            */

/**** Command line options ****/

#  define  VG_PARET_OPTCHGTEMP               701     /* Can't find the charge template  */
#  define  VG_PARET_OPTCOLUNK                702     /* Unknown color                   */
#  define  VG_PARET_OPTFILEMISS              703     /* Missing input file name         */
#  define  VG_PARET_OPTFLOATNUM              704     /* Argument must be unsigned float */
#  define  VG_PARET_OPTILLDIEL               705     /* Illegal dielectric constant     */
#  define  VG_PARET_OPTILLPRORAD             706     /* Illegal probe radius            */
#  define  VG_PARET_OPTILLRESNAM             707     /* Illegal residue name            */
#  define  VG_PARET_OPTILLSASDEN             708     /* Illegal SAS density             */
#  define  VG_PARET_OPTILLSOLRAD             709     /* Illegal solvatation radius      */
#  define  VG_PARET_OPTILLSTRRES             710     /* Illegal starting residue        */
#  define  VG_PARET_OPTINTNUM                711     /* Argument must be an unsigned int*/
#  define  VG_PARET_OPTOGLPORT               712     /* Invalid port number             */
#  define  VG_PARET_OPTOGLRUN                713     /* VEGA OpenGL already running     */
#  define  VG_PARET_SRFINVNUM                714     /* Invalid surface number          */
#  define  VG_PARET_OPTSUBARG                715     /* Missing sub-argument            */
#  define  VG_PARET_OPTUNK                   716     /* Unknown option                  */
#  define  VG_PARET_OPTUNKSHAPE              717     /* Unknown shape type              */
#  define  VG_PARET_OPTUNKSHELL              718     /* Shell file not found            */
#  define  VG_PARET_OPTUNSCHGTMP             719     /* Unsupported charge template     */
#  define  VG_PARET_OPTWIN32                 720     /* Option available only in Win32  */
#  define  VG_PARET_OPTCALCRUN               721     /* Calculation already running     */
#  define  VG_PARET_OPTBNDFIX                722     /* Unknown bond fix method         */
#  define  VG_PARET_OPTMOLDEL                723     /* Invalid molecule ID             */
#  define  VG_PARET_OPTMOLSEG                724     /* Invalid segment ID              */

/**** Console ****/

#  define  VG_PARET_CONSAVEBUF               801     /* Unable to save the buffer       */

/**** Secondary structure ****/

#  define  VG_PARET_SSTRNOPROT               811     /* The molecule isn't a protein    */
#  define  VG_PARET_SSTRNOTOR                812     /* No valid torsions               */
#  define  VG_PARET_SSTRTORNAME              813     /* Invalid torsion name            */

/**** GL initialisation ****/

#  define  VG_PARET_GLINIACTCON             1001     /* Can't activate the GL context   */
#  define  VG_PARET_GLINICONTEXT            1002     /* Can't create GL device context  */
#  define  VG_PARET_GLINICRCONTXT           1003     /* Can't create GL rend. context   */
#  define  VG_PARET_GLINIFAIL               1004     /* OpenGL initialization failed    */
#  define  VG_PARET_GLINIPXFORM1            1005     /* Can't find suitable pixelformat */
#  define  VG_PARET_GLINIPXFORM2            1006     /* Can't set the pixel format      */
#  define  VG_PARET_GLINIWNDCLASS           1007     /* Failed to register window class */
#  define  VG_PARET_GLINIWNDCREAT           1008     /* Window creation error           */
#  define  VG_PARET_PBUFFER_CANTALLOCATE    1009     /* Can't allocate the pixel buffer */
#  define  VG_PARET_PBUFFER_EXT             1010     /* Unable to load the extension    */
#  define  VG_PARET_PBUFFER_NOOGLEXTENSIONS 1011     /* OpenGL extensions not supported */
#  define  VG_PARET_PBUFFER_NOPIXELFORMAT   1012     /* No pixel format ARB             */
#  define  VG_PARET_PBUFFER_NOTAVAIL        1013     /* Pixel buffer not available      */
#  define  VG_PARET_PBUFFER_UNKPROB         1014     /* Unknown problem                 */

/**** GL generic ****/

#  define  VG_PARET_GLCOLUNK                1101     /* Unknown color                   */
#  define  VG_PARET_GLDEVIL                 1102     /* DevIL error                     */
#  define  VG_PARET_GLFMOD                  1103     /* Fmod error                      */
#  define  VG_PARET_GLMENCANTEXE            1104     /* Can't execute                   */
#  define  VG_PARET_GLMENHELP               1105     /* Can't open help file            */
#  define  VG_PARET_GLDEMONOTINST           1106     /* Demo files not installed        */
#  define  VG_PARET_GLGL2VRML               1107     /* Gl2Vrml error                   */

/**** GL Mopac ****/

#  define  VG_PARET_GLMOPACEXE              1201     /* Can't find MoPac executable     */
#  define  VG_PARET_GLMOPACNOARC            1202     /* Abnormal termination            */
#  define  VG_PARET_GLMOPACTOOATM           1203     /* Too many atoms                  */

/**** GL BioDock ****/

#  define  VG_PARET_GLBDARGMIS              1301     /* Missing argument                */
#  define  VG_PARET_GLBDBEGMIS              1302     /* Missing BEGIN command           */
#  define  VG_PARET_GLBDCONVFACT            1303     /* The value must be lower than 1  */
#  define  VG_PARET_GLBDDUPCOM              1304     /* Command duplicated              */
#  define  VG_PARET_GLBDFRMSELINV           1305     /* Invalid selection of frames     */
#  define  VG_PARET_GLBDFRMSELMIS           1306     /* Missing selection of frames     */
#  define  VG_PARET_GLBDMACROCLS            1307     /* Field already closed in macro   */
#  define  VG_PARET_GLBDMACROFREQ           1308     /* Field required                  */
#  define  VG_PARET_GLBDMACRONCLS           1309     /* Field not closed in macro       */
#  define  VG_PARET_GLBDMACRONOPN           1310     /* Field not opened in macro       */
#  define  VG_PARET_GLBDMACROOPN            1311     /* Field already opened in macro   */
#  define  VG_PARET_GLBDMISCOM              1312     /* Missing command                 */
#  define  VG_PARET_GLBDMODULE              1313     /* Unknown module                  */
#  define  VG_PARET_GLBDNULLSTR             1314     /* Null string not allowed         */
#  define  VG_PARET_GLBDNUMBOOL             1315     /* Boolean value required          */
#  define  VG_PARET_GLBDNUMFLOAT            1316     /* Float number required           */
#  define  VG_PARET_GLBDNUMFRM              1317     /* Illegal number of frames (> 1)  */
#  define  VG_PARET_GLBDNUMNULL             1318     /* The value can't be zero         */
#  define  VG_PARET_GLBDNUMINT              1319     /* Integer number required         */
#  define  VG_PARET_GLBDNUMPOS              1320     /* Positive integer required       */
#  define  VG_PARET_GLBDROTPOS              1321     /* The rotation ranges must be +   */
#  define  VG_PARET_GLBDTOOLINES            1322     /* The input file exceeds 65535 l. */
#  define  VG_PARET_GLBDTRANSPOS            1323     /* The trans. ranges must be +     */
#  define  VG_PARET_GLBDUNKCOM              1324     /* Unknown command                 */
#  define  VG_PARET_GLBDUNKEXTRA            1325     /* Unknown extraction mode         */
#  define  VG_PARET_GLBDUNKOPTMET           1326     /* Unknown optimization method     */
#  define  VG_PARET_GLBDUNTERMSTR           1327     /* Unterminated string             */
#  define  VG_PARET_GLBDBIODOCKEXE          1328     /* Can't find BioDock executable   */
#  define  VG_PARET_GLBDBIOPRJ              1329     /* Can't open BioDock input file   */
#  define  VG_PARET_GLBDBIOOUT              1330     /* Unrecognized BioDock output     */
#  define  VG_PARET_GLBSTRUCTOUT            1331     /* BioDock output corrupted        */

/**** GL measure ****/

#  define  VG_PARET_GLMEASATMMULTI          1401     /* Multiple selection              */
#  define  VG_PARET_GLMEASATMNFND           1402     /* Atom not found                  */

/**** GL select ****/

#  define  VG_PARET_GLSELDONTMATCH          1501     /* The selection doesn't match     */
#  define  VG_PARET_GLSELILLNUMARG          1502     /* Illegal number of arguments     */
#  define  VG_PARET_GLSELUNKTAG             1503     /* Unknown tag                     */

/**** GL SkyBox ****/

#  define  VG_PARET_GLSKBAR                 1511     /* The texture AR must be 2:1      */
#  define  VG_PARET_GLSKDATAFMT             1512     /* Pixel format not RGB            */
#  define  VG_PARET_GLSKFACEBMP             1513     /* Can't buid the face bitmaps     */
#  define  VG_PARET_GLSKINIT                1514     /* Initialization error            */

/**** ESCHER Next Generation ****/

#  define  VG_PARET_GLESCORRFILE            1601     /* Corrupted ESCHER file           */
#  define  VG_PARET_GLESNUMSOL              1602     /* Illegal number of solutions     */
#  define  VG_PARET_GLESUNKFORMAT           1603     /* Unknown format                  */

/**** GRAMM ****/

#  define  VG_PARET_GRAMMFRMNUM             1611     /* Invalid number of poses         */
#  define  VG_PARET_GRAMMLIGRANGE           1612     /* Invalid atom range              */
#  define  VG_PARET_GRAMMLIGSEL             1613     /* Atom selection not found        */

/**** Graph Editor ****/

#  define  VG_PARET_GRAPH_ILLID             1701    /* Illegal GraphEd ID               */
#  define  VG_PARET_GRAPH_NOCUR             1702    /* No GraphEd window opened         */
#  define  VG_PARET_GRAPH_NODATA            1703    /* No data in plot                  */
#  define  VG_PARET_GRAPH_POINTRNG          1704    /* Point out of range               */
#  define  VG_PARET_GRAPH_EXCEL             1705    /* Exel export                      */
#  define  VG_PARET_GRAPH_EXCELTMR          1706    /* Excel too many records           */
#  define  VG_PARET_GRAPH_OLE               1707    /* OLE initialization               */

/**** Database engine ****/

#  define  VG_PARET_DBCREATE                1801     /* Can't create the database                     */
#  define  VG_PARET_DBINVHANDLE             1802     /* Invalid database handle                       */
#  define  VG_PARET_DBGET                   1803     /* Unable to get the molecule                    */
#  define  VG_PARET_DBMOLLIST               1804     /* Unable to read the mol. catalog               */
#  define  VG_PARET_DBOPEN                  1805     /* Database already opened                       */
#  define  VG_PARET_DBPUT                   1806     /* Unable to put the molecule                    */
#  define  VG_PARET_DBREMOVE                1807     /* Unable to remove the molecule                 */
#  define  VG_PARET_DBREN                   1808     /* Unable to rename the molecule                 */
#  define  VG_PARET_DBSQLSUPP               1809     /* Database doesn't support SQL                  */
#  define  VG_PARET_DBUNKFOR                1810     /* Unknown database format                       */
#  define  VG_PARET_DBUPDATE                1811     /* Unable to update the molecule                 */
#  define  VG_PARET_DBZIP32INIT             1812     /* The zip32.dll can't be init.                  */
#  define  VG_PARET_DBDAT                   1813     /* Unknown format of .dat file                   */
#  define  VG_PARET_DBODBCCONNECT           1814     /* Unable to connect to ODBC database            */
#  define  VG_PARET_DBODBCHANDLE            1815     /* Unable to allocate the ODBC handle            */
#  define  VG_PARET_DBODBCVERSION           1816     /* Unable to check the ODBC version              */
#  define  VG_PARET_DBSQLITEOPEN            1817     /* Unable to open the SQLite database            */
#  define  VG_PARET_DBSQLITESETPAR          1818     /* Unable to set the SQLite parameters           */
#  define  VG_PARET_DBSQLITESTRUCT          1819     /* Unable to attach SQLite structure database    */
#  define  VG_PARET_DBSQLITEVEGATAB         1820     /* Missing control data in SQLite database       */
#  define  VG_PARET_DBZIPOPEN               1821     /* Unable to open the Zip archive                */
#  define  VG_PARET_DBUPDDATA               1822     /* Unable to update the data                     */

#  define  VG_PARET_DBCOLADD                1823     /* Can't add the column                          */
#  define  VG_PARET_DBCOLUPDATE             1824     /* Can't update the columns                      */
#  define  VG_PARET_DBPASTELINEMATCH        1825     /* The number of lines don't match               */
#  define  VG_PARET_DBPASTECOLNUM           1826     /* Incompatible number of columns                */
#  define  VG_PARET_DBPASTEDATATYPE         1827     /* Unsupported data type                         */
#  define  VG_PARET_DBPASTEDATATYPEINC      1828     /* Incompatible data type                        */
#  define  VG_PARET_DBPASTENOTHING          1829     /* Nothing to paste                              */
#  define  VG_PARET_DBCOLDELETE             1830     /* Can't delete the column                       */
#  define  VG_PARET_DBCOLRENAME             1831     /* Can't rename the column                       */

/**** Database report ****/

#  define  VG_PARET_DBREPHEAD               1851     /* Unable to find the report head                */
#  define  VG_PARET_DBREPLOAD               1852     /* Unable to load the report template            */
#  define  VG_PARET_DBREPMISEOS             1853     /* Missing end of section                        */
#  define  VG_PARET_DBREPPROMPT             1854     /* Token error                                   */
#  define  VG_PARET_DBREPTAIL               1855     /* Unable to find the report tail                */

/**** Energy engine ****/

#  define  VG_PARET_ENEPARKEYUNK            1901     /* Unknown parameter key                         */

/**** Ammp ****/

#  define  VG_PARET_AMMPCOMLOST             2001     /* Ammp communication lost                       */
#  define  VG_PARET_AMMPCONNECT             2002     /* Unable to connect to host                     */
#  define  VG_PARET_AMMPDATA                2003     /* Unable to send data to Ammp                   */
#  define  VG_PARET_AMMPEXE                 2004     /* Can't find the Ammp executable                */
#  define  VG_PARET_AMMPHOSTUSED            2005     /* Host already in use                           */
#  define  VG_PARET_AMMPNOFREEHOST          2006     /* No free host available                        */
#  define  VG_PARET_AMMPMOLECULE            2007     /* Unable to send the molecule                   */
#  define  VG_PARET_AMMPPIPEINIT            2008     /* Unable to initialize pipe                     */
#  define  VG_PARET_AMMPSAVESP4             2009     /* Can't load the SP4 parameters                 */
#  define  VG_PARET_AMMPSAVEASSFF           2010     /* Can't assign the force field                  */
#  define  VG_PARET_AMMPSAVEFF              2011     /* Can't open the force field                    */
#  define  VG_PARET_AMMPSAVECHKFF           2012     /* One or more atoms have an undefined atom type */

/**** CML ****/

#  define  VG_PARET_CMLABORT                2101     /* Parsing aborted                               */
#  define  VG_PARET_CMLPARSE                2102     /* Parsing error                                 */
#  define  VG_PARET_CMLPARSER               2103     /* Unable to create the parser                   */
#  define  VG_PARET_CMLSTACK                2104     /* Unable to allocate the stack                  */

/**** InChI ****/

#  define  VG_PARET_INCHIINTERNAL           2111     /* InChI library internal error                  */
#  define  VG_PARET_INCHIPROMPT             2112     /* InChI library error                           */

/**** Cano ****/

#  define  VG_PARET_CANOPROMPT              2121     /* Cano library error                            */

/**** Dingo ****/

#  define  VG_PARET_DINGOPROMPT             2131     /* Dingo library error                           */

/**** OPSIN ****/

#  define  VG_PARET_OPSINIUPAC              2141     /* Invalid IUPAC name                            */
#  define  VG_PARET_OPSINNOTINST            2142     /* OPSIN not installed                           */
#  define  VG_PARET_OPSINRUN                2143     /* Can't run OPSIN                               */

/**** NAMD ****/

#  define  VG_PARET_NAMDCOORDS              2201     /* Unable to read the remote coordinates         */
#  define  VG_PARET_NAMDENDIAN              2202     /* Ascertain relative endianness of remote host  */
#  define  VG_PARET_NAMDENERGIES            2203     /* Unable to read the energies                   */
#  define  VG_PARET_NAMDLOADPROMPT          2204     /* NAMD input load error                         */
#  define  VG_PARET_NAMDMUTEX               2205     /* Unable to create mutex                        */
#  define  VG_PARET_NAMDNONBONDEDFREQ       2206     /* fullElectFrequency isn't stepspercycle factor */
#  define  VG_PARET_NAMDNOTINSTALLED        2207     /* NAMD not installed                            */
#  define  VG_PARET_NAMDPAIRLISTDIST        2208     /* pailistdist < cutoff                          */
#  define  VG_PARET_NAMDPARFILE             2209     /* Unable to open the parameter file             */
#  define  VG_PARET_NAMDPMEGRIDSIZEX        2210     /* PMEGridSizeX must be factor of 2, 3, 5        */
#  define  VG_PARET_NAMDPMEGRIDSIZEY        2211     /* PMEGridSizeY must be factor of 2, 3, 5        */
#  define  VG_PARET_NAMDPMEGRIDSIZEZ        2212     /* PMEGridSizeZ must be factor of 2, 3, 5        */
#  define  VG_PARET_NAMDREADFORCE           2213     /* Unable to read indices and forces             */
#  define  VG_PARET_NAMDSENDFORCE           2214     /* Unable to send indices and forces             */
#  define  VG_PARET_NAMDSWITCHDIST          2215     /* switchdist < cutoff                           */
#  define  VG_PARET_NAMDTCPPORT             2216     /* Unable to find a free TCP/IP port             */

/**** Isotopic distribution errors ****/

#  define  VG_PARET_ISOFRMELEM              2301     /* Invalid element in formula                    */
#  define  VG_PARET_ISOFRMINV               2302     /* Invalid formula                               */
#  define  VG_PARET_ISOFRMINVCHAR           2303     /* Invalid character in formula                  */
#  define  VG_PARET_ISOFRMINVINDEX          2304     /* Invalid index in formula                      */
#  define  VG_PARET_ISOTABEMPTY             2305     /* The table of isotopes is empty                */
#  define  VG_PARET_ISOTABINVMASS           2306     /* The table of isotopes with an invalid mass    */
#  define  VG_PARET_ISOTABNOTFOUND          2307     /* File of isotopes not found                    */
#  define  VG_PARET_ISOTABUNKFORMAT         2308     /* File of isotopes in unknown format            */

/**** Interaction energy (score) ****/

#  define  VG_PARET_SCOREENESEL             2401     /* Score function not selected                   */
#  define  VG_PARET_SCOREENETYP             2402     /* Unknown interaction energy type               */
#  define  VG_PARET_SCORELIG                2403     /* Invalid ligand number                         */
#  define  VG_PARET_SCOREPAR                2404     /* Unable to assign the parameters               */
#  define  VG_PARET_SCOREONEMOL             2405     /* At least two molecules are required           */
#  define  VG_PARET_SCOREPOT                2406     /* Can't assign the potential                    */

/**** Ionize ****/

#  define VG_PARET_IONIZENOPAR              2501     /* Ionize - Parameters not availabe              */

/**** Windows errors ****/

#  define  VG_PARET_WINDOWS                 3001     /* Windows error                                 */
#  define  VG_PARET_WINDOWSFADDR            3002     /* Can't get the function address                */
#  define  VG_PARET_WINDOWSDLL              3003     /* Can't open the DLL                            */
#  define  VG_PARET_WINDOWSMCI              3004     /* Windows MCI error                             */

/**** AVI errors ****/

#  define  VG_PARET_AVIADD                  3101     /* Add frame error                               */
#  define  VG_PARET_AVICREATE               3102     /* Create AVI file error                         */
#  define  VG_PARET_AVISET                  3103     /* Compression settings                          */
#  define  VG_PARET_AVIMULTX                3104     /* Incompatible width                            */
#  define  VG_PARET_AVIMULTY                3105     /* Incompatible height                           */

/**** VEGA GL errors ****/

#  define  VG_PARET_VGL_BEGINGROUPEXP       3201     /* VglBeginGroup expected                        */
#  define  VG_PARET_VGL_INVGROUPID          3202     /* Invalid group ID                              */
#  define  VG_PARET_VGL_MTXSTACK            3203     /* Matrix stack out of bounds                    */
#  define  VG_PARET_VGL_PRIMITIVE           3204     /* Primitive already initialized                 */
#  define  VG_PARET_VGL_TOOMANYGROUPS       3205     /* Too many groups                               */

/**** Undo errors ****/

#  define  VG_PARET_UNDO_CREATE             3301     /* Can't create a new uno level                  */
#  define  VG_PARET_UNDO_INTERNAL           3302     /* Internal error                                */

/**** Recovery errors ****/

#  define  VG_PARET_EXCEPT_DUMP             3401     /* Unable to dump one or more mol.               */

/**** Update errors ****/

#  define  VG_PARET_UPD_ALRRUN              3501     /* Update already running                        */
#  define  VG_PARET_UPD_CONN                3502     /* Internet connection not available             */
#  define  VG_PARET_UPD_CORRFILE            3503     /* Corrupted update file                         */
#  define  VG_PARET_UPD_CORRPACK            3504     /* Corrupted package list                        */
#  define  VG_PARET_UPD_DATA                3505     /* Unable to download update data                */
#  define  VG_PARET_UPD_DIR                 3506     /* Unable to create the download directory       */
#  define  VG_PARET_UPD_DOWNLOAD            3507     /* Unable to download the update file            */
#  define  VG_PARET_UPD_RUNCPY              3508     /* Run.exe not found                             */
#  define  VG_PARET_UPD_SCRIPT              3509     /* Unable to save the update script              */
#  define  VG_PARET_UPD_SCRIPTRUN           3510     /* Unable to start the update script             */
#  define  VG_PARET_UPD_URLINV              3511     /* Invalid update URL                            */
#  define  VG_PARET_UPD_URLMIS              3512     /* Missing update URL in configuration file      */

/**** OpenVR ****/

#  define  VG_PARET_OVR_INIT                3601     /* Unable to initialize the OpenVR context       */

/**** License errors ****/

#  define  VG_PARET_DLGACT_EXPIRED          8001     /* License expired                               */
#  define  VG_PARET_DLGACT_INVCRC           8002     /* Invalid CRC                                   */
#  define  VG_PARET_DLGACT_INVHOST          8003     /* Invalid host                                  */
#  define  VG_PARET_DLGACT_INVSIGN          8004     /* Invalid signature                             */
#  define  VG_PARET_DLGACT_IFFCSIZE         8005     /* Invalid chunk size                            */
#  define  VG_PARET_DLGACT_IFFFORMAT        8006     /* Not in requested file format                  */
#  define  VG_PARET_DLGACT_IFFSIZE          8007     /* Invalid file size                             */
#  define  VG_PARET_DLGACT_INVCRYP          8008     /* Invalid encryption                            */
#  define  VG_PARET_DLGACT_NOIFF            8009     /* Not in IFF file format                        */
#  define  VG_PARET_DLGACT_READ             8010     /* Unable to read the license                    */
#  define  VG_PARET_DLGACT_UNKNOWN          8011     /* Unknown license error                         */
#  define  VG_PARET_DLGACT_LIVE             8012     /* Live license                                  */

#  define  VG_PARET_UNKERR                  9000     /* Unknown error                                 */

#  define  VG_PARET_CLIPBOARD               9999     /* Return data in clipboard                      */


/**** Error translation table ****/

struct _ErrTab {
  HD_UWORD      ErrCode;
  HD_UWORD      StrId;
};

#  ifdef __VG_ERRTRANSTAB

const struct _ErrTab ErrTab[] = {

  /**** Command line ****/

  {VG_PARET_AGPATMNUM              , MSG_ERR_ARGPAR_ATMNUM           },
  {VG_PARET_AGPDUPDESC             , MSG_ERR_ARGPAR_DUPDESC          },
  {VG_PARET_AGPILLATN              , MSG_ERR_ARGPAR_ILLATMNUM        },
  {VG_PARET_AGPILLNMES             , MSG_ERR_ARGPAR_ILLNUMMES        },
  {VG_PARET_AGPINCDESC             , MSG_ERR_ARGPAR_INCDESC          },
  {VG_PARET_AGPINPFILE             , MSG_ERR_ARGPAR_INPFILE          },
  {VG_PARET_AGPMATCH               , MSG_ERR_ARGPAR_MATCH            },
  {VG_PARET_AGPTOOFEW              , MSG_ERR_ARGPAR_TOOFEW           },
  {VG_PARET_AGPTOOLONG             , MSG_ERR_ARGPAR_TOOLONG          },
  {VG_PARET_AGPUNKMES              , MSG_ERR_ARGPAR_UNKMES           },

  {VG_PARET_ARGPARFRMINV           , MSG_ERR_ARGPAR_FRMINV           },
  {VG_PARET_ARGPARFRMINVFIRST      , MSG_ERR_ARGPAR_FRMINVFIRST      },
  {VG_PARET_ARGPARFRMINVLAST       , MSG_ERR_ARGPAR_FRMINVLAST       },
  {VG_PARET_ARGPARFRMMIS           , MSG_ERR_ARGPAR_FRMMIS           },
  {VG_PARET_ARGPARFRMRNG           , MSG_ERR_ARGPAR_FRMRNG           },

  {VG_PARET_ARGCPUS                , MSG_ERR_CPUS                    },
  {VG_PARET_ARGMEASTRJ             , MSG_ERR_MAIN_MEASURETRJ         },
  {VG_PARET_ARGINFOXML             , MSG_ERR_INFOXML_KEYWORD         },
  {VG_PARET_ARGCAPCTERM            , MSG_ERR_MAIN_CAPCTERM           },
  {VG_PARET_ARGCAPNTERM            , MSG_ERR_MAIN_CAPNTERM           },

  /**** Calculations ****/

  {VG_PARET_CALEFFNOTASS           , MSG_ERR_ENER_FFNOTASS           },
  {VG_PARET_CALENNOFF              , MSG_ERR_ENER_FFNOTFOUND         },
  {VG_PARET_CALENNOBOND            , MSG_ERR_ENER_NONBOND            },
  {VG_PARET_CALENRES               , MSG_ERR_ENER_MORERES            },
  {VG_PARET_CALENRESNF             , MSG_ERR_ENER_RESNOTFOUND        },
  {VG_PARET_CALENUNKTYP            , MSG_ERR_ENER_UNKATMTYPE         },
  {VG_PARET_CALLOGPNOPAR           , MSG_ERR_LOGP_NOTALLPAR          },
  {VG_PARET_CALLOGNOTF             , MSG_ERR_LOGP_NOTFOUND           },
  {VG_PARET_CALLOGPUNREC           , MSG_ERR_LOGP_UNRECFILE          },
  {VG_PARET_CALNOVLOGP             , MSG_ERR_MLP_NOVLOGP             },
  {VG_PARET_CALSRFILM              , MSG_ERR_SURFACE_ILM             },
  {VG_PARET_CALCLUSTTBIG           , MSG_ERR_DLGCLUSTBLD_TOOBIG      },

  /**** Charge and potential ****/

  {VG_PARET_CHGNOTASS              , MSG_DLGCHG_ERR_NOTASS           },
  {VG_PARET_CHGTEMATMLONG          , MSG_ERR_CHARGE_TEMATMLONG       },
  {VG_PARET_CHGTEMATMMIS           , MSG_ERR_CHARGE_TEMATMMIS        },
  {VG_PARET_CHGTEMBONDINV          , MSG_ERR_CHARGE_TEMBONDINV       },
  {VG_PARET_CHGTEMBONDMIS          , MSG_ERR_CHARGE_TEMBONDMIS       },
  {VG_PARET_CHGTEMCALLITS          , MSG_ERR_CHARGE_TEMCALLITS       },
  {VG_PARET_CHGTEMDEL              , MSG_ERR_CHARGE_TEMDEL           },
  {VG_PARET_CHGTEMDESCDUP          , MSG_ERR_CHARGE_TEMDESCDUP       },
  {VG_PARET_CHGTEMDESCLONG         , MSG_ERR_CHARGE_TEMDESCLONG      },
  {VG_PARET_CHGTEMFORMAT           , MSG_ERR_CHARGE_TEMFORMAT        },
  {VG_PARET_CHGTEMGRPINV           , MSG_ERR_CHARGE_TEMGRPINV        },
  {VG_PARET_CHGTEMGRPMIS           , MSG_ERR_CHARGE_TEMGRPMIS        },
  {VG_PARET_CHGTEMIDDUP            , MSG_ERR_CHARGE_TEMIDDUP         },
  {VG_PARET_CHGTEMIDLONG           , MSG_ERR_CHARGE_TEMIDLONG        },
  {VG_PARET_CHGTEMIDMIS            , MSG_ERR_CHARGE_TEMIDMIS         },
  {VG_PARET_CHGTEMIDUNI            , MSG_ERR_CHARGE_TEMIDUNI         },
  {VG_PARET_CHGTEMIDUNK            , MSG_ERR_CHARGE_TEMIDUNK         },
  {VG_PARET_CHGTEMRESEXP           , MSG_ERR_CHARGE_TEMRESEXP        },
  {VG_PARET_CHGTEMRESLONG          , MSG_ERR_CHARGE_TEMRESLONG       },
  {VG_PARET_CHGTEMRESMIS           , MSG_ERR_CHARGE_TEMRESMIS        },

  /**** Database engine ****/

  {VG_PARET_DBCREATE               , MSG_ERR_DBENGINE_CREATE           },
  {VG_PARET_DBINVHANDLE            , MSG_ERR_DBENGINE_INVHANDLE        },
  {VG_PARET_DBMOLLIST              , MSG_ERR_DBENGINE_MOLLIST          },
  {VG_PARET_DBGET                  , MSG_ERR_DBENGINE_GET              },
  {VG_PARET_DBOPEN                 , MSG_ERR_DBENGINE_OPEN             },
  {VG_PARET_DBPUT                  , MSG_ERR_DBENGINE_PUT              },
  {VG_PARET_DBREMOVE               , MSG_ERR_DBENGINE_REMOVE           },
  {VG_PARET_DBREN                  , MSG_ERR_DBENGINE_REN              },
  {VG_PARET_DBSQLSUPP              , MSG_ERR_DBENGINE_SQLSUPP          },
  {VG_PARET_DBUNKFOR               , MSG_ERR_DBENGINE_UNKFOR           },
  {VG_PARET_DBUPDATE               , MSG_ERR_DBENGINE_UPDATE           },
  {VG_PARET_DBZIP32INIT            , MSG_ERR_DBENGINE_ZIP32INIT        },
  {VG_PARET_DBDAT                  , MSG_ERR_DBENGINE_DAT              },
  {VG_PARET_DBODBCCONNECT          , MSG_ERR_DBENGINE_ODBC_CONNECT     },
  {VG_PARET_DBODBCHANDLE           , MSG_ERR_DBENGINE_ODBC_HANDLE      },
  {VG_PARET_DBODBCVERSION          , MSG_ERR_DBENGINE_ODBC_VERSION     },
  {VG_PARET_DBSQLITEOPEN           , MSG_ERR_DBENGINE_SQLITE_OPEN      },
  {VG_PARET_DBSQLITESETPAR         , MSG_ERR_DBENGINE_SQLITE_SETPAR    },
  {VG_PARET_DBSQLITESTRUCT         , MSG_ERR_DBENGINE_SQLITE_STRUCT    },
  {VG_PARET_DBSQLITEVEGATAB        , MSG_ERR_DBENGINE_SQLITE_VEGATAB   },
  {VG_PARET_DBZIPOPEN              , MSG_ERR_DBENGINE_ZIP_OPEN         },
  {VG_PARET_DBUPDDATA              , MSG_ERR_DBENGINE_UPDDATA          },
  {VG_PARET_DBCOLADD               , MSG_ERR_DBENGINE_COLADD           },
  {VG_PARET_DBCOLUPDATE            , MSG_ERR_DBENGINE_COLUPDATE        },
  {VG_PARET_DBPASTELINEMATCH       , MSG_ERR_DBENGINE_PASTE_LINEMATCH  },
  {VG_PARET_DBPASTECOLNUM          , MSG_ERR_DBENGINE_PASTE_COLNUM     },
  {VG_PARET_DBPASTEDATATYPE        , MSG_ERR_DBENGINE_PASTE_DATATYPE   },
  {VG_PARET_DBPASTEDATATYPEINC     , MSG_ERR_DBENGINE_PASTE_DATATYPEINC},
  {VG_PARET_DBPASTENOTHING         , MSG_ERR_DBENGINE_PASTE_NOTHING    },
  {VG_PARET_DBCOLDELETE            , MSG_ERR_DBENGINE_COLDELETE        },
  {VG_PARET_DBCOLRENAME            , MSG_ERR_DBENGINE_COLRENAME        },

  /**** Database report ****/

  {VG_PARET_DBREPHEAD              , MSG_ERR_DBREP_HEAD              },
  {VG_PARET_DBREPLOAD              , MSG_ERR_DBREP_LOAD              },
  {VG_PARET_DBREPMISEOS            , MSG_ERR_DBREP_MISENDOFSEC       },
  {VG_PARET_DBREPPROMPT            , MSG_ERR_DBREP_PROMPT            },
  {VG_PARET_DBREPTAIL              , MSG_ERR_DBREP_TAIL              },

  /**** Energy engine ****/

  {VG_PARET_ENEPARKEYUNK           , MSG_ERR_ENER_PARKEYUNK          },

  /**** Ammp ****/

  {VG_PARET_AMMPCOMLOST            , MSG_ERR_AMMP_COMLOST            },
  {VG_PARET_AMMPCONNECT            , MSG_ERR_AMMP_CONNECT            },
  {VG_PARET_AMMPDATA               , MSG_ERR_AMMP_DATA               },
  {VG_PARET_AMMPEXE                , MSG_ERR_AMMP_EXE                },
  {VG_PARET_AMMPHOSTUSED           , MSG_ERR_AMMP_HOSTUSED           },
  {VG_PARET_AMMPNOFREEHOST         , MSG_ERR_AMMP_NOFREEHOST         },
  {VG_PARET_AMMPMOLECULE           , MSG_ERR_AMMP_MOLECULE           },
  {VG_PARET_AMMPPIPEINIT           , MSG_ERR_AMMP_PIPEINIT           },
  {VG_PARET_AMMPSAVEASSFF          , MSG_ERR_AMMP_SAVE_ASSFF         },
  {VG_PARET_AMMPSAVECHKFF          , MSG_ERR_AMMP_SAVE_CHKFF         },
  {VG_PARET_AMMPSAVESP4            , MSG_ERR_AMMP_SAVE_SP4           },
  {VG_PARET_AMMPSAVEFF             , MSG_ERR_AMMP_SAVE_FF            },

  /**** Command arguments ****/

  {VG_PARET_EXCRANGE               , MSG_ERR_COM_EXCRANGEF           },
  {VG_PARET_EXCRANGE               , MSG_ERR_COM_EXCRANGEI           },
  {VG_PARET_EXCRANGE               , MSG_ERR_COM_EXCRANGEUI          },
  {VG_PARET_EXCRANGE               , MSG_ERR_COM_EXCRANGEC           },

  /**** Trajectory analysis ****/

  {VG_PARET_DCDSELECT              , MSG_ERR_ANA_SELECT              },
  {VG_PARET_DCDGRAPH               , MSG_ERR_ANA_GRAPH               },
  {VG_PARET_DCDUNCHARGED           , MSG_ERR_DCD_UNCHARGED           },
  {VG_PARET_DCDUNCHARGED           , MSG_ERR_UNCHARGED               },
  {VG_PARET_DCDUNKTRAJ             , MSG_ERR_DCD_UNKTRAJ             },
  {VG_PARET_DCDUNSOUT              , MSG_ERR_DCD_UNSUPPOUT           },
  {VG_PARET_DCDNOMOL               , MSG_ERR_DCD_NOMOL               },
  {VG_PARET_DCDNOOUT               , MSG_ERR_DCD_NOOUT               },
  {VG_PARET_DCDRMSDNOSRF           , MSG_ERR_DCD_RMSDNOSRF           },
  {VG_PARET_DCDRMSDNOTRAJ          , MSG_ERR_DCD_RMSDNOTRAJ          },
  {VG_PARET_DCDRMSDUNCOMPM         , MSG_DCD_ERR_RMSDUNCOMPMOL       },
  {VG_PARET_DCDSAMEFILE            , MSG_ERR_DCD_SAMEFILE            },
  {VG_PARET_TRAJINVHANDLE          , MSG_ERR_TRAJ_INVHANDLE          },
  {VG_PARET_DCDATMNUM              , MSG_ERR_DCD_ATMNUM              },
  {VG_PARET_AUTODOCKCORR           , MSG_ERR_AUTODOCK_CORR           },

  /**** ESCHER Next Generation ****/

  {VG_PARET_GLESCORRFILE           , MSG_ERR_ESCHER_CORRFILE         },
  {VG_PARET_GLESNUMSOL             , MSG_ERR_ESCHER_NUMSOL           },
  {VG_PARET_GLESUNKFORMAT          , MSG_ERR_ESCHER_UNKFORMAT        },

  /**** GRAMM ****/

  {VG_PARET_GRAMMFRMNUM            , MSG_ERR_GRAMM_FRMNUM            },
  {VG_PARET_GRAMMLIGRANGE          , MSG_ERR_GRAMM_LIGRANGE          },
  {VG_PARET_GRAMMLIGSEL            , MSG_ERR_GRAMM_LIGSEL            },

  /**** Graph Editor ****/

  {VG_PARET_GRAPH_ILLID            , MSG_ERR_GRAPH_ILLID             },
  {VG_PARET_GRAPH_NOCUR            , MSG_ERR_GRAPH_NOCUR             },
  {VG_PARET_GRAPH_NODATA           , MSG_ERR_GRAPH_NODATA            },
  {VG_PARET_GRAPH_POINTRNG         , MSG_ERR_GRAPH_POINTRANGE        },
  {VG_PARET_GRAPH_EXCEL            , MSG_ERR_GRAPH_EXCEL             },
  {VG_PARET_GRAPH_EXCELTMR         , MSG_ERR_GRAPH_EXCEL_TOOMANYREC  },
  {VG_PARET_GRAPH_OLE              , MSG_ERR_GRAPH_OLE               },

  /**** Force field ****/

  {VG_PARET_FFATYTOOLG             , MSG_ERR_FFIELD_ATYPTOOLONG      },
  {VG_PARET_FFCANTASS              , MSG_ERR_FFIELD_CANTASSIGN       },
  {VG_PARET_FFILLNUM               , MSG_ERR_FFIELD_ILLNUM           },
  {VG_PARET_FFINCATM               , MSG_ERR_FFIELD_INCATM           },
  {VG_PARET_FFINCSATM              , MSG_ERR_FFIELD_INCSUBATM        },
  {VG_PARET_FFNOTFOUND             , MSG_ERR_FFIELD_NOTFOUND         },
  {VG_PARET_FFNOTFOUND             , MSG_ERR_MAIN_FFNOTFOUND         },
  {VG_PARET_FFNOTSTD               , MSG_ERR_MAIN_FFNOTSTD           },
  {VG_PARET_FFSUBLVL               , MSG_ERR_FFIELD_SUBLVL           },
  {VG_PARET_FFUNBPAR               , MSG_ERR_FFIELD_UNBPAR           },
  {VG_PARET_FFILLAROM              , MSG_ERR_FFIELD_ILLAROM          },
  {VG_PARET_FFILLBONDORD           , MSG_ERR_FFIELD_ILLBONDORD       },
  {VG_PARET_FFILLRING              , MSG_ERR_FFIELD_ILLRING          },
  {VG_PARET_FFINVELEM              , MSG_ERR_FFIELD_INVELEM          },
  {VG_PARET_FFINVOP                , MSG_ERR_FFIELD_INVOP            },
  {VG_PARET_FFMULTIOP              , MSG_ERR_FFIELD_MULTIOP          },
  {VG_PARET_FFREQOP                , MSG_ERR_FFIELD_REQOP            },
  {VG_PARET_FFSMARTSFILE           , MSG_ERR_FFIELD_SMARTSFILE       },
  {VG_PARET_FFSMARTSINV            , MSG_ERR_FFIELD_SMARTSINV        },

  /**** Secondary structure ****/

  {VG_PARET_SSTRNOPROT             , MSG_ERR_SSTR_NOPROT             },
  {VG_PARET_SSTRNOTOR              , MSG_ERR_SSTR_NOTOR              },
  {VG_PARET_SSTRTORNAME            , MSG_ERR_SSTR_TORNAME            },

#    ifdef VEGA_ZZ

  /**** Console ****/

  {VG_PARET_CONSAVEBUF             , MSG_ERR_CON_SAVEBUF             },

  /**** GL BioDock ****/

  {VG_PARET_GLBDARGMIS             , MSG_BIODOCK_ERR_ARGMIS          },
  {VG_PARET_GLBDBEGMIS             , MSG_BIODOCK_ERR_BEGMIS          },
  {VG_PARET_GLBDBIODOCKEXE         , MSG_ERR_BIODOCK_BIODOCKEXE      },
  {VG_PARET_GLBDBIOOUT             , MSG_ERR_BIODOCK_BIOOUT          },
  {VG_PARET_GLBDBIOPRJ             , MSG_ERR_BIODOCK_BIOPRJ          },
  {VG_PARET_GLBDCONVFACT           , MSG_BIODOCK_ERR_CONVFACT        },
  {VG_PARET_GLBDDUPCOM             , MSG_BIODOCK_ERR_DUPCOM          },
  {VG_PARET_GLBDFRMSELINV          , MSG_BIODOCK_ERR_FRMSELINV       },
  {VG_PARET_GLBDFRMSELMIS          , MSG_BIODOCK_ERR_FRMSELMIS       },
  {VG_PARET_GLBDMACROCLS           , MSG_BIODOCK_ERR_MACROCLOSED     },
  {VG_PARET_GLBDMACROFREQ          , MSG_BIODOCK_ERR_MACROFREQ       },
  {VG_PARET_GLBDMACRONCLS          , MSG_BIODOCK_ERR_MACRONOTCLOSED  },
  {VG_PARET_GLBDMACRONOPN          , MSG_BIODOCK_ERR_MACRONOTOPENED  },
  {VG_PARET_GLBDMACROOPN           , MSG_BIODOCK_ERR_MACROOPENED     },
  {VG_PARET_GLBDMISCOM             , MSG_BIODOCK_ERR_MISCOM          },
  {VG_PARET_GLBDMODULE             , MSG_BIODOCK_ERR_MODULE          },
  {VG_PARET_GLBDNULLSTR            , MSG_BIODOCK_ERR_NULLSTR         },
  {VG_PARET_GLBDNUMBOOL            , MSG_BIODOCK_ERR_NUMBOOL         },
  {VG_PARET_GLBDNUMFLOAT           , MSG_BIODOCK_ERR_NUMFLOAT        },
  {VG_PARET_GLBDNUMFRM             , MSG_BIODOCK_ERR_NUMFRM          },
  {VG_PARET_GLBDNUMINT             , MSG_BIODOCK_ERR_NUMINT          },
  {VG_PARET_GLBDNUMNULL            , MSG_BIODOCK_ERR_NULLNUM         },
  {VG_PARET_GLBDNUMPOS             , MSG_BIODOCK_ERR_NUMPOS          },
  {VG_PARET_GLBDROTPOS             , MSG_BIODOCK_ERR_ROTPOS          },
  {VG_PARET_GLBSTRUCTOUT           , MSG_ERR_BIODOCK_STRUCTOUT       },
  {VG_PARET_GLBDTOOLINES           , MSG_BIODOCK_ERR_TOOLINES        },
  {VG_PARET_GLBDTRANSPOS           , MSG_BIODOCK_ERR_TRANSPOS        },
  {VG_PARET_GLBDUNKCOM             , MSG_BIODOCK_ERR_UNKCOM          },
  {VG_PARET_GLBDUNKEXTRA           , MSG_BIODOCK_ERR_UNKEXTRA        },
  {VG_PARET_GLBDUNKOPTMET          , MSG_BIODOCK_ERR_UNKOPTMET       },
  {VG_PARET_GLBDUNTERMSTR          , MSG_BIODOCK_ERR_UNTERMSTR       },

  /**** GL initialisation ****/

  {VG_PARET_GLINIACTCON            , MSG_ERR_GL_ACTCONTEXT           },
  {VG_PARET_GLINICONTEXT           , MSG_ERR_GL_CONTEXT              },
  {VG_PARET_GLINICRCONTXT          , MSG_ERR_GL_CREATECONTEXT        },
  {VG_PARET_GLINIFAIL              , MSG_ERR_GL_FAIL                 },
  {VG_PARET_GLINIPXFORM1           , MSG_ERR_GL_PIXELFORM1           },
  {VG_PARET_GLINIPXFORM2           , MSG_ERR_GL_PIXELFORM2           },
  {VG_PARET_GLINIWNDCLASS          , MSG_ERR_GL_WNDCLASS             },
  {VG_PARET_GLINIWNDCREAT          , MSG_ERR_GL_WNDCREAT             },
  {VG_PARET_PBUFFER_CANTALLOCATE   , MSG_ERR_PBUFFER_CANTALLOCATE    },
  {VG_PARET_PBUFFER_EXT            , MSG_ERR_PBUFFER_EXT             },
  {VG_PARET_PBUFFER_NOOGLEXTENSIONS, MSG_ERR_PBUFFER_NOOGLEXTENSIONS },
  {VG_PARET_PBUFFER_NOPIXELFORMAT  , MSG_ERR_PBUFFER_NOPIXELFORMAT   },
  {VG_PARET_PBUFFER_NOTAVAIL       , MSG_ERR_PBUFFER_NOTAVAIL        },
  {VG_PARET_PBUFFER_UNKPROB        , MSG_ERR_PBUFFER_UNKPROB         },

  /**** GL generic ****/

  {VG_PARET_GLDEVIL                , MSG_ERR_DEVIL_PROMPT            },
  {VG_PARET_GLFMOD                 , MSG_ERR_FMOD_PROMPT             },
  {VG_PARET_GLMENCANTEXE           , MSG_MENU_ERR_CANTEXE            },
  {VG_PARET_GLMENHELP              , MSG_MENU_ERR_HELP               },
  {VG_PARET_GLDEMONOTINST          , MSG_GLDEMO_ERR_NOTINST          },
  {VG_PARET_GLGL2VRML              , MSG_ERR_GL2VRML_PROMPT          },

  /**** GL measure ****/

  {VG_PARET_GLMEASATMMULTI         , MSG_GLMEAS_ERR_ATMMULTI         },
  {VG_PARET_GLMEASATMNFND          , MSG_GLMEAS_ERR_ATMNOTFND        },

  /**** GL Mopac ****/

  {VG_PARET_GLMOPACNOARC           , MSG_ERR_DLGMOPAC_NOARC          },
  {VG_PARET_GLMOPACEXE             , MSG_ERR_DLGMOPAC_MOPACEXE       },
  {VG_PARET_GLMOPACTOOATM          , MSG_ERR_DLGMOPAC_TOOATM         },

  /**** GL select ****/

  {VG_PARET_GLSELDONTMATCH         , MSG_SEL_ERR_DONTMATCH           },
  {VG_PARET_GLSELILLNUMARG         , MSG_SEL_ERR_ILLNUMARG           },
  {VG_PARET_GLSELUNKTAG            , MSG_SEL_ERR_UNKTAG              },

  /**** GL SkyBox ****/

  {VG_PARET_GLSKBAR                , MSG_ERR_SKYBOX_AR               },
  {VG_PARET_GLSKDATAFMT            , MSG_ERR_SKYBOX_DATAFORMAT       },
  {VG_PARET_GLSKFACEBMP            , MSG_ERR_SKYBOX_FACEBMP          },
  {VG_PARET_GLSKINIT               , MSG_ERR_SKYBOX_INIT             },

#    endif

  {VG_PARET_FEWARGS                , MSG_ERR_COM_FEWARGS             },
  {VG_PARET_ILLARG                 , MSG_ERR_COM_ILLARG              },

  /**** Input/Output ****/

  {VG_PARET_IOBZIP2                , MSG_ERR_BZIP2_ERROR             },
  {VG_PARET_IOCANTPACK             , MSG_ERR_MAIN_CANTPACK           },
  {VG_PARET_IODOS                  , MSG_ERR_UTILS_DOSERR            },
  {VG_PARET_IOGZIP                 , MSG_ERR_GZIP_ERROR              },
  {VG_PARET_IONOSTDOUT             , MSG_ERR_MAIN_NOSTDOUT           },
  {VG_PARET_IOPKSTDOUT             , MSG_ERR_MAIN_PKNOSTDOUT         },
  {VG_PARET_IOPOWERPK              , MSG_ERR_PKPP_ERROR              },
  {VG_PARET_IOPOWERPKCR            , MSG_ERR_PKPP_NOCRUNCH           },
  {VG_PARET_IOPOWERPKLIB           , MSG_ERR_PKPP_NOPPLIB            },
  {VG_PARET_IOPOWERPSHORT          , MSG_ERR_PKPP_TOOSHORT           },
  {VG_PARET_IOUNKPACK              , MSG_ERR_MAIN_UNKPACKMET         },
  {VG_PARET_IOVEGADIR              , MSG_ERR_UTILS_VEGADIR           },
  {VG_PARET_IOZ32                  , MSG_ERR_Z32_ERROR               },

  {VG_PARET_IODOWNLOAD             , MSG_ERR_TCPIO_DOWNLOAD          },
  {VG_PARET_IOHTTPINIT             , MSG_ERR_TCPIO_HTTPINIT          },
  {VG_PARET_IOPARSEURL             , MSG_ERR_TCPIO_PARSEURL          },

#    ifdef VEGA_ZZ

  /**** Merge ****/

  {VG_PARET_MERGEUNALLELEM         , MSG_DLGMERGE_ERR_UNALLELEM      },
  {VG_PARET_MERGEUNCOMP            , MSG_DLGMERGE_ERR_UNCOMPMOL      },

#    endif

  /**** Load and save operations ****/

  {VG_PARET_MOLBIOSNS              , MSG_ERR_BIOSYM_NOTSUPPORTED     },
  {VG_PARET_MOLCOMFAFL             , MSG_ERR_COMFA_FIELD             },
  {VG_PARET_MOLCOMFARG             , MSG_ERR_COMFA_RGN               },

  {VG_PARET_MOLCONBORD             , MSG_ERR_CONNECT_UNACCBD         },
  {VG_PARET_MOLCONVDW              , MSG_ERR_CONNECT_UNKVDW          },

  {VG_PARET_MOLCRDASS              , MSG_ERR_LOADER_CRDASSFILE       },
  {VG_PARET_MOLCRDMEAS             , MSG_ERR_LOADER_CRDMESURE        },

  {VG_PARET_MOLCSSR                , MSG_ERR_MAIN_CSSR               },
  {VG_PARET_MOLCSSR                , MSG_ERR_MAIN_MDLMOL             },
  {VG_PARET_MOLFASTA               , MSG_ERR_FASTA_NOPROT            },

  {VG_PARET_MOLIFFCORR             , MSG_ERR_IFF_CORRUPTED           },
  {VG_PARET_MOLIFFINV              , MSG_ERR_IFF_INVFILE             },
  {VG_PARET_MOLIFFNOT              , MSG_ERR_IFF_NOTIFF              },
  {VG_PARET_MOLIFFREAD             , MSG_ERR_IFF_READ                },
  {VG_PARET_MOLIFFWRITE            , MSG_ERR_IFF_WRITE               },

  {VG_PARET_MOLMOL2CORR            , MSG_ERR_MOL2_CORRUPTED          },
  {VG_PARET_MOLMOL2NOTF            , MSG_ERR_MOL2_NOTFOUND           },
  {VG_PARET_MOLMOL2TEMP            , MSG_ERR_MOL2_ILLTEMP            },

  {VG_PARET_MOLMSFFORMAT           , MSG_ERR_MSF_NOTMSF              },
  {VG_PARET_MOLMSFNCOMP            , MSG_ERR_MSF_NOTCOMP             },

  {VG_PARET_MOLMOPACATOM           , MSG_ERR_MOPAC_ATMFAULT          },
  {VG_PARET_MOLMOPACBADCON         , MSG_ERR_MOPAC_BADCONV           },
  {VG_PARET_MOLNOCHARGE            , MSG_ERR_MAIN_NOCHARGE           },
  {VG_PARET_MOLNOFFTAG             , MSG_ERR_MAIN_NOFFTAG            },
  {VG_PARET_MOLNOTFOUND            , MSG_ERR_LOADER_NOTFOUND         },

  {VG_PARET_MOLRGNCORRUPT          , MSG_ERR_SYBRGN_CORRUPTED        },
  {VG_PARET_MOLRGNNOMOL            , MSG_ERR_MAIN_RGNNOMOL           },
  {VG_PARET_MOLRGNNUMSTPS          , MSG_ERR_SYBRGN_NUMSTPS          },
  {VG_PARET_MOLRGNPOINTS           , MSG_ERR_SYBRGN_POINTS           },
  {VG_PARET_MOLRGNSTPSIZE          , MSG_ERR_SYBRGN_STPSIZE          },
  {VG_PARET_MOLUNKINFOR            , MSG_ERR_LOADER_UNKFORMAT        },
  {VG_PARET_MOLUNKOUTFOR           , MSG_ERR_MAIN_UNKOUTFOR          },
  {VG_PARET_SRFNOMOL               , MSG_ERR_SRFNOMOL                },
  {VG_PARET_MOLTYPE                , MSG_ERR_MAIN_MOLTYPE            },
  {VG_PARET_MOLINFOXML             , MSG_ERR_INFOXML_NOTHING         },
  {VG_PARET_RMHYDROG               , MSG_ERR_MAIN_RMHYDROG           },
  {VG_PARET_TORTYPE                , MSG_ERR_MAIN_TORTYPE            },
  {VG_PARET_DBEXMODE               , MSG_ERR_MAIN_DBEXMODE           },
  {VG_PARET_DBINVREC               , MSG_ERR_MAIN_DBINVREC           },
  {VG_PARET_DBNOTFOUND             , MSG_ERR_MAIN_DBNOTFOUND         },
  {VG_PARET_DBTOOMANY              , MSG_ERR_MAIN_DBTOOMANY          },
  {VG_PARET_DBSQL                  , MSG_ERR_DBENGINE_SQL            },
  {VG_PARET_R2DUNKFORMAT           , MSG_ERR_R2D_UNKFORMAT           },
  {VG_PARET_WKSLOCKMOL             , MSG_ERR_WKSLOCKMOL              },
  {VG_PARET_SPILLOMISLIG           , MSG_ERR_SPILLO_MISLIG           },

  /**** Command line options ****/

  {VG_PARET_OPTCHGTEMP             , MSG_ERR_MAIN_CHGFILENOTFOUND    },
  {VG_PARET_OPTCOLUNK              , MSG_ERR_COM_COLUNK              },
  {VG_PARET_OPTCALCRUN             , MSG_ERR_COM_CALCRUN             },
  {VG_PARET_OPTFILEMISS            , MSG_ERR_MAIN_FILEMISS           },
  {VG_PARET_OPTFLOATNUM            , MSG_ERR_MAIN_FLOATNUM           },
  {VG_PARET_OPTILLDIEL             , MSG_ERR_MAIN_ILLDIEL            },
  {VG_PARET_OPTILLPRORAD           , MSG_ERR_MAIN_ILLPROBERAD        },
  {VG_PARET_OPTILLRESNAM           , MSG_ERR_MAIN_ILLRESNAME         },
  {VG_PARET_OPTILLSASDEN           , MSG_ERR_MAIN_ILLSASDEN          },
  {VG_PARET_OPTILLSOLRAD           , MSG_ERR_MAIN_ILLSOLRAD          },
  {VG_PARET_OPTILLSTRRES           , MSG_ERR_MAIN_ILLSTRRES          },
  {VG_PARET_OPTINTNUM              , MSG_ERR_MAIN_INTNUM             },
  {VG_PARET_OPTOGLPORT             , MSG_ERR_MAIN_INVALIDPORT        },
  {VG_PARET_OPTOGLRUN              , MSG_ERR_GL_RUNNING              },
  {VG_PARET_SRFINVNUM              , MSG_ERR_COM_SRFINVNUM           },
  {VG_PARET_OPTSUBARG              , MSG_ERR_MAIN_SUBARG             },
  {VG_PARET_OPTUNK                 , MSG_ERR_MAIN_UNKOPT             },
  {VG_PARET_OPTUNKSHELL            , MSG_ERR_MAIN_SHELLFILE          },
  {VG_PARET_OPTUNKSHAPE            , MSG_ERR_MAIN_UNKSHAPE           },
  {VG_PARET_OPTUNSCHGTMP           , MSG_ERR_MAIN_UNSUPCHGTEMP       },
  {VG_PARET_OPTWIN32               , MSG_ERR_MAIN_WIN32ONLY          },
  {VG_PARET_OPTBNDFIX              , MSG_ERR_BOND_FIXTYPE            },
  {VG_PARET_OPTMOLDEL              , MSG_ERR_COM_MOLDELETE           },
  {VG_PARET_OPTMOLSEG              , MSG_ERR_COM_SEGDELETE           },

  /**** Plots ****/

  {VG_PARET_PLOTSAVER              , MSG_ERR_SAVER_PLOT              },
  {VG_PARET_PLOTPOINTRANGE         , MSG_ERR_GRAPH_POINTRANGE        },

  /**** Solvatation ****/

  {VG_PARET_SOLCANTOPEN            , MSG_ERR_SOLVATE_CANTOPEN        },
  {VG_PARET_SOLSHELLDIM            , MSG_ERR_SOLVATE_SHELLDIM        },
  {VG_PARET_SOLNOTHING             , MSG_ERR_SOLVATE_NOTHING         },

  /**** Command parser ****/

  {VG_PARET_ABORT                  , MSG_ERR_MAIN_ABORT              },
  {VG_PARET_JAVANOTINST            , MSG_ERR_JAVA_NOTINSTALLED       },
  {VG_PARET_NOCOM                  , MSG_ERR_COM_NOCOM               },
  {VG_PARET_NOMOL                  , MSG_ERR_COM_NOMOL               },
  {VG_PARET_NOSRF                  , MSG_ERR_COM_NOSRF               },
  {VG_PARET_NOTIMP                 , MSG_ERR_COM_NOTIMP              },
  {VG_PARET_NOTRJ                  , MSG_ERR_COM_NOTRJ               },
  {VG_PARET_OGLONLY                , MSG_ERR_LODER_OPENGLONLY        },
  {VG_PARET_OUTOFMEM               , MSG_ERR_UTILS_OUTOFMEM          },
  {VG_PARET_TOOARGS                , MSG_ERR_COM_TOOARGS             },
  {VG_PARET_UNKCOM                 , MSG_ERR_COM_UNKCOM              },
  {VG_PARET_UNKKEYWORD             , MSG_ERR_COM_UNKKEYWORD          },

  /**** CML ****/

  {VG_PARET_CMLABORT               , MSG_ERR_CML_ABORT               },
  {VG_PARET_CMLPARSE               , MSG_ERR_CML_PARSE               },
  {VG_PARET_CMLPARSER              , MSG_ERR_CML_PARSER              },
  {VG_PARET_CMLSTACK               , MSG_ERR_CML_STACK               },

  /**** InChI ****/

  {VG_PARET_INCHIINTERNAL          , MSG_ERR_INCHI_INTERNAL          },
  {VG_PARET_INCHIPROMPT            , MSG_ERR_INCHI_PROMPT            },

  /**** Cano ****/

  {VG_PARET_CANOPROMPT             , MSG_ERR_CANO_PROMPT             },

  /**** Dingo ****/

  {VG_PARET_DINGOPROMPT            , MSG_ERR_INDIGO_PROMPT           },

  /**** OPSIN ****/

  {VG_PARET_OPSINIUPAC             , MSG_ERR_IUPAC_NAME              },
  {VG_PARET_OPSINNOTINST           , MSG_ERR_OPSIN_NOTINSTALLED      },
  {VG_PARET_OPSINRUN               , MSG_ERR_OPSIN_CANTRUN           },

  /**** NAMD ****/

  {VG_PARET_NAMDCOORDS             , MSG_ERR_NAMD_COORDS             },
  {VG_PARET_NAMDENDIAN             , MSG_ERR_NAMD_ENDIAN             },
  {VG_PARET_NAMDENERGIES           , MSG_ERR_NAMD_ENERGIES           },
  {VG_PARET_NAMDLOADPROMPT         , MSG_ERR_NAMD_LOAD_PROMPT        },
  {VG_PARET_NAMDMUTEX              , MSG_ERR_NAMD_MUTEX              },
  {VG_PARET_NAMDNONBONDEDFREQ      , MSG_ERR_NAMD_FULLELECTFREQUENCY },
  {VG_PARET_NAMDNOTINSTALLED       , MSG_ERR_NAMD_NOTINSTALLED       },
  {VG_PARET_NAMDPAIRLISTDIST       , MSG_ERR_NAMD_PAIRLISTDIST       },
  {VG_PARET_NAMDPARFILE            , MSG_ERR_NAMD_PARFILE            },
  {VG_PARET_NAMDPMEGRIDSIZEX       , MSG_ERR_NAMD_PMEGRIDSIZEX       },
  {VG_PARET_NAMDPMEGRIDSIZEY       , MSG_ERR_NAMD_PMEGRIDSIZEY       },
  {VG_PARET_NAMDPMEGRIDSIZEZ       , MSG_ERR_NAMD_PMEGRIDSIZEZ       },
  {VG_PARET_NAMDREADFORCE          , MSG_ERR_NAMD_READFORCE          },
  {VG_PARET_NAMDSENDFORCE          , MSG_ERR_NAMD_SENDFORCE          },
  {VG_PARET_NAMDSWITCHDIST         , MSG_ERR_NAMD_SWITCHDIST         },
  {VG_PARET_NAMDTCPPORT            , MSG_ERR_NAMD_TCPPORT            },

  /**** Isotopic distribution errors ****/

  {VG_PARET_ISOFRMELEM             , MSG_ERR_ISOTOPIC_FRMELEM        },
  {VG_PARET_ISOFRMINV              , MSG_ERR_ISOTOPIC_FRMINV         },
  {VG_PARET_ISOFRMINVCHAR          , MSG_ERR_ISOTOPIC_FRMINVCHAR     },
  {VG_PARET_ISOFRMINVINDEX         , MSG_ERR_ISOTOPIC_FRMINVINDEX    },
  {VG_PARET_ISOTABEMPTY            , MSG_ERR_ISOTOPIC_TABEMPTY       },
  {VG_PARET_ISOTABINVMASS          , MSG_ERR_ISOTOPIC_TABINVMASS     },
  {VG_PARET_ISOTABNOTFOUND         , MSG_ERR_ISOTOPIC_TABNOTFOUND    },
  {VG_PARET_ISOTABUNKFORMAT        , MSG_ERR_ISOTOPIC_TABUNKFORMAT   },

  /**** Interaction energy (score) ****/

  {VG_PARET_SCOREENESEL            , MSG_ERR_SCORE_ENESEL            },
  {VG_PARET_SCOREENETYP            , MSG_ERR_SCORE_ENETYP            },
  {VG_PARET_SCORELIG               , MSG_ERR_SCORE_LIG               },
  {VG_PARET_SCOREPAR               , MSG_ERR_SCORE_PAR               },
  {VG_PARET_SCOREONEMOL            , MSG_ERR_SCORE_ONEMOL            },
  {VG_PARET_SCOREPOT               , MSG_ERR_SCORE_POT               },

  /**** Dynamic library error ****/

  {VG_PARET_WINDOWSFADDR           , MSG_ERR_WIN_CANTGETADDR         },
  {VG_PARET_WINDOWSDLL             , MSG_ERR_WIN_CANTLOADLIB         },


  /**** Ionize ****/

  {VG_PARET_IONIZENOPAR            , MSG_ERR_IONIZE_NOPAR            },

#    ifdef WIN32

  /**** Windows errors ****/

  {VG_PARET_WINDOWSMCI             , MSG_GLDEMO_ERR_MCI              },

  /**** AVI errors ****/

  {VG_PARET_AVIADD                 , MSG_ERR_AVI_ADD                 },
  {VG_PARET_AVICREATE              , MSG_ERR_AVI_CREATE              },
  {VG_PARET_AVISET                 , MSG_ERR_AVI_SET                 },
  {VG_PARET_AVIMULTX               , MSG_ERR_DLGCODEC_MULTX          },
  {VG_PARET_AVIMULTY               , MSG_ERR_DLGCODEC_MULTY          },

#    endif

  /**** VEGA GL errors ****/

#    ifdef VEGA_ZZ

  {VG_PARET_VGL_BEGINGROUPEXP      , MSG_ERR_VGL_BEGINGROUPEXP       },
  {VG_PARET_VGL_INVGROUPID         , MSG_ERR_VGL_INVGROUPID          },
  {VG_PARET_VGL_MTXSTACK           , MSG_ERR_VGL_MTXSTACK            },
  {VG_PARET_VGL_PRIMITIVE          , MSG_ERR_VGL_PRIMITIVE           },
  {VG_PARET_VGL_TOOMANYGROUPS      , MSG_ERR_VGL_TOOMANYGROUPS       },

  /**** Undo errors ****/

  {VG_PARET_UNDO_CREATE            , MSG_ERR_UNDO_CREATE             },
  {VG_PARET_UNDO_INTERNAL          , MSG_ERR_UNDO_INTERNAL           },

  /**** Recovery errors ****/

  {VG_PARET_EXCEPT_DUMP            , MSG_ERR_EXCEPT_DUMP             },

  /**** Update errors ****/

  {VG_PARET_UPD_ALRRUN             , MSG_ERR_UPDATE_ALRRUN           },
  {VG_PARET_UPD_CONN               , MSG_ERR_UPDATE_CONN             },
  {VG_PARET_UPD_CORRFILE           , MSG_ERR_UPDATE_CORRFILE         },
  {VG_PARET_UPD_CORRPACK           , MSG_ERR_UPDATE_CORRPACK         },
  {VG_PARET_UPD_DATA               , MSG_ERR_UPDATE_DATA             },
  {VG_PARET_UPD_DIR                , MSG_ERR_UPDATE_DIR              },
  {VG_PARET_UPD_DOWNLOAD           , MSG_ERR_UPDATE_DOWNLOAD         },
  {VG_PARET_UPD_RUNCPY             , MSG_ERR_UPDATE_RUNCPY           },
  {VG_PARET_UPD_SCRIPT             , MSG_ERR_UPDATE_SCRIPT           },
  {VG_PARET_UPD_SCRIPTRUN          , MSG_ERR_UPDATE_SCRIPTRUN        },
  {VG_PARET_UPD_URLINV             , MSG_ERR_UPDATE_URLINV           },
  {VG_PARET_UPD_URLMIS             , MSG_ERR_UPDATE_URLMIS           },

  /**** OpenVR ****/

  {VG_PARET_OVR_INIT               , MSG_ERR_OPENVR_INIT             },
#    endif

  /**** License errors ****/

  {VG_PARET_DLGACT_EXPIRED         , MSG_ERR_DLGACT_EXPIRED          },
  {VG_PARET_DLGACT_INVCRC          , MSG_ERR_DLGACT_INVCRC           },
  {VG_PARET_DLGACT_INVHOST         , MSG_ERR_DLGACT_INVHOST          },
  {VG_PARET_DLGACT_INVSIGN         , MSG_ERR_DLGACT_INVSIGN          },
  {VG_PARET_DLGACT_IFFCSIZE        , MSG_ERR_DLGACT_IFFCSIZE         },
  {VG_PARET_DLGACT_IFFFORMAT       , MSG_ERR_DLGACT_IFFFORMAT        },
  {VG_PARET_DLGACT_IFFSIZE         , MSG_ERR_DLGACT_IFFSIZE          },
  {VG_PARET_DLGACT_INVCRYP         , MSG_ERR_DLGACT_INVCRYP          },
  {VG_PARET_DLGACT_NOIFF           , MSG_ERR_DLGACT_NOIFF            },
  {VG_PARET_DLGACT_READ            , MSG_ERR_DLGACT_READ             },
  {VG_PARET_DLGACT_UNKNOWN         , MSG_ERR_DLGACT_UNKNOWN          },
  {VG_PARET_DLGACT_LIVE            , MSG_ERR_DLGACT_LIVE             },

  {VG_PARET_UNKERR                 , MSG_ERR_COM_UNKERR              }
};
#  else
extern const struct _ErrTab ErrTab[];
#  endif
#endif

