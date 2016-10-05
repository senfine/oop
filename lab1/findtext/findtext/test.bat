set findtext="%~1"

%findtext% > nul
if not errorlevel 1 goto err 

%findtext% ReadMe.txt Project
if errorlevel 1 goto err

%findtext% ReadMe.txt Kozlovsky
if not errorlevel 1 goto err

echo Program testing succeeded
exit /b 0

:err
echo Program testing failed
exit /b 1

