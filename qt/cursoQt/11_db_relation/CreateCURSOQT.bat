set ORACLE_SID=CURSOQT
set ORACLE_BASE=C:\oraclexe\oradata\oradata
set ORACLE_HOME=C:\oraclexe\app\oracle

if not exist "%ORACLE_BASE%\admin\%ORACLE_SID%\pfile" mkdir %ORACLE_BASE%\admin\%ORACLE_SID%\pfile
if not exist "%ORACLE_BASE%\admin\%ORACLE_SID%\bdump" mkdir %ORACLE_BASE%\admin\%ORACLE_SID%\bdump
if not exist "%ORACLE_BASE%\admin\%ORACLE_SID%\cdump" mkdir %ORACLE_BASE%\admin\%ORACLE_SID%\cdump
if not exist "%ORACLE_BASE%\admin\%ORACLE_SID%\udump" mkdir %ORACLE_BASE%\admin\%ORACLE_SID%\udump
if not exist "%ORACLE_BASE%\oradata\%ORACLE_SID%" mkdir %ORACLE_BASE%\oradata\%ORACLE_SID%

copy "C:\cursoQtLabs\18_db_relation\initCURSOQT.ora" %ORACLE_BASE%\admin\%ORACLE_SID%\pfile

%ORACLE_HOME%\bin\orapwd FILE=%ORACLE_BASE%\admin\%ORACLE_SID%\pfile\%ORACLE_SID% PASSWORD=ORACLE ENTRIES=10
%ORACLE_HOME%\bin\oradim -new -sid %ORACLE_SID% -intpwd oracle -startmode manual -pfile "%ORACLE_BASE%\admin\%ORACLE_SID%\pfile\init%ORACLE_SID%.ora"
%ORACLE_HOME%\bin\sqlplus "sys/oracle as sysdba" @C:\cursoQtLabs\18_db_relation\CreateCURSOQT.sql
%ORACLE_HOME%\bin\oradim -edit -sid %ORACLE_SID% -startmode auto

echo %ORACLE_SID% =  >> %ORACLE_HOME%\network\admin\tnsnames.ora
echo  (DESCRIPTION =  >> %ORACLE_HOME%\network\admin\tnsnames.ora
echo    (ADDRESS_LIST =  >> %ORACLE_HOME%\network\admin\tnsnames.ora
echo      (ADDRESS = (PROTOCOL = TCP)(HOST = 127.0.0.1)(PORT = 1521)) >> %ORACLE_HOME%\network\admin\tnsnames.ora
echo    ) >> %ORACLE_HOME%\network\admin\tnsnames.ora
echo    (CONNECT_DATA = >> %ORACLE_HOME%\network\admin\tnsnames.ora
echo      (SERVICE_NAME = %ORACLE_SID%) >> %ORACLE_HOME%\network\admin\tnsnames.ora
echo    ) >> %ORACLE_HOME%\network\admin\tnsnames.ora
echo  ) >> %ORACLE_HOME%\network\admin\tnsnames.ora

