set echo on
spool "C:\cursoQtLabs\18_db_relation\CreateCURSOQT.log"
startup nomount pfile="%ORACLE_BASE%\admin\%ORACLE_SID%\pfile\initCURSOQT.ora"
create spfile='spfile%ORACLE_SID%.ora' from pfile='%ORACLE_BASE%\admin\%ORACLE_SID%\pfile\init%ORACLE_SID%.ora';set verify off

CREATE DATABASE CURSOQT
  controlfile reuse
  undo tablespace undo
  datafile '%ORACLE_BASE%\oradata\%ORACLE_SID%\rbs01.dbf' size 32M reuse
  NOARCHIVELOG
  CHARACTER SET UTF8
  NATIONAL CHARACTER SET AL16UTF16
  logfile
    '%ORACLE_BASE%\oradata\%ORACLE_SID%\redo_log01.dbf' size 8M reuse, 
    '%ORACLE_BASE%\oradata\%ORACLE_SID%\redo_log02.dbf' size 8M reuse
  SYSAUX DATAFILE '%ORACLE_BASE%\oradata\%ORACLE_SID%\sysaux01.dbf' size 32M reuse
  datafile '%ORACLE_BASE%\oradata\%ORACLE_SID%\system01.dbf' size 200M reuse;

create temporary tablespace TEMP
tempfile '%ORACLE_BASE%\oradata\%ORACLE_SID%\temp01.dbf' size 32M reuse;

create tablespace TOOLS
datafile '%ORACLE_BASE%\oradata\%ORACLE_SID%\tools01.dbf' size 32M reuse
logging;


create tablespace USER_DATA
datafile '%ORACLE_BASE%\oradata\%ORACLE_SID%\udata01.dbf' size 32M reuse
logging;


create tablespace USER_INDEX
datafile '%ORACLE_BASE%\oradata\%ORACLE_SID%\uindex01.dbf' size 32M reuse
logging;

alter user sys temporary tablespace TEMP;
alter user system temporary tablespace TEMP;

grant sysdba to sys;
grant sysdba to system;

@"C:\oraclexe\app\oracle\rdbms\admin\catalog.sql"
@"C:\oraclexe\app\oracle\rdbms\admin\catproc.sql"
@"C:\oraclexe\app\oracle\sqlplus\admin\pupbld.sql"



shutdown
exit
