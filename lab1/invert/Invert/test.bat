set invert="%~1"

rem Совпадение ответов с результатом
@echo off
%invert% test1.txt > result.txt
fc answer1.txt result.txt
if ERRORLEVEL 1 goto err

rem Совпадение ответов с результатом
%invert% test2.txt > result.txt
fc answer2.txt result.txt
if ERRORLEVEL 1 goto err

echo answers are the same
exit /b 0

rem Несовпадение ответов с результатом
:err
echo answers are not the same
pause
exit /b 1


rem добавать тесты для проверки аргументов и тест с пустой матрицей

rem Проверка на несуществующий файл
%invert% NotExist.txt > "%TEMP%\output1.txt"
if not errorlevel 1 goto err
fc "%TEMP%\output1.txt" notexist.txt
if errorlevel 1 goto err

rem Проверка на неправильное количество параметров
%invert% > "%TEMP%\output1.txt"
if not errorlevel 1 goto err
fc "%TEMP%\output1.txt" invalid_arguments_count.txt
if errorlevel 1 goto err