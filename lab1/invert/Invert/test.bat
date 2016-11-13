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