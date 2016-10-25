set findtext="%~1"

rem ��� ������� � ������������� ����������� ���������� �������� �� ������
%findtext% > nul
if not errorlevel 1 goto err 

rem ����� ������������� ������ � �����
%findtext% ReadMe.txt Project > "%TEMP%\output1.txt"
if errorlevel 1 goto err
fc "%TEMP%\output1.txt" readme-Project.txt
if errorlevel 1 goto err

rem ����� ������, �������������� �� ���������� �������
%findtext% ReadMe.txt findtext > "%TEMP%\output1.txt"
if errorlevel 1 goto err
fc "%TEMP%\output1.txt" readme-findtext.txt
if errorlevel 1 goto err

rem ����� ��������������� ������ � �����
%findtext% ReadMe.txt Kozlovsky
if not errorlevel 1 goto err

rem TODO: �������� ����, �����������, ��� ������� ������ �� ����� ���� ������
rem ��������� ������� ������� � ���� ������ ��������� � output

rem �������� �� ��, ��� ������� ������ �� ����� ���� ������
%findtext% ReadMe.txt "" > "%TEMP%\output1.txt"
if not errorlevel 1 goto err
fc "%TEMP%\output1.txt" readme-emptyneedle.txt
if errorlevel 1 goto err

rem TODO: �������� ����, ����������� ������ ���������, ����� ������� ���� ������� �� �������
rem ��������� ������ �������� �� ������

rem ��������, ����� ������� ���� ������� �� �������
%findtext% NotExist.txt findtext > "%TEMP%\output1.txt"
if not errorlevel 1 goto err
fc "%TEMP%\output1.txt" readme-notexist.txt
if errorlevel 1 goto err

echo Program testing succeeded
exit /b 0

:err
echo Program testing failed
exit /b 1

