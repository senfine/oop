set invert="%~1"

rem ���������� ������� � �����������
@echo off
%invert% test1.txt > result.txt
fc answer1.txt result.txt
if ERRORLEVEL 1 goto err

rem ���������� ������� � �����������
%invert% test2.txt > result.txt
fc answer2.txt result.txt
if ERRORLEVEL 1 goto err

echo answers are the same
exit /b 0

rem ������������ ������� � �����������
:err
echo answers are not the same
pause
exit /b 1