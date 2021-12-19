@echo off

set /a numb=500

:loop
set /a sqare = %numb%*%numb%
set /a ost=%square%%%1000000

if "%ost%"=="269696" (goto :exit)
set /a numb=%numb%+1
goto :loop


:exit
echo %numb%
pause
