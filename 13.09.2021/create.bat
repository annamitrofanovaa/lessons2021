@echo off
chcp 65001 > nul

SET /p dirname="Enter dir - "
md %dirname%

md %dirname%\"Алгебра и геометрия"
echo Погожев Сергей Владимирович > %dirname%\"Алгебра и геометрия"\readme.txt
echo Начало занятий: %date% >> %dirname%\"Алгебра и геометрия"\readme.txt

md %dirname%\"Матанализ"
echo Платонов Алексей Виткторович > %dirname%\"Мат анализ"\readme.txt
echo Начало занятий: %date% >> %dirname%\"Мат анализ"\readme.txt

md %dirname%\"Основы программирования"
echo Погожев Сергей Владимирович > %dirname%\"Основы программирования"\readme.txt
echo Начало занятий: %date% >> %dirname%\"Основы программирования"\readme.txt

md %dirname%\"Дискретная математика"
echo Погожев Сергей Владимирович > %dirname%\"Дискретная математика"\readme.txt
echo Начало занятий: %date% >> %dirname%\"Дискретная математика"\readme.txt

copy op.bat %dirname%
copy algem.bat %dirname%
