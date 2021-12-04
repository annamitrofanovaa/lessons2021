@echo off

set string=%1
:loop
if "%string%"=="" (goto :yes)
if not "%string:~0,1%"=="%string:~-1%" (goto :no)
set string=%string:~1,-1%
goto :loop

:yes
echo yes
exit /b

:no
echo no
exit /b
