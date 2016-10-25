set findtext="%~1"

rem При запуске с недостаточным количеством аргументов сообщаем об ошибке
%findtext% > nul
if not errorlevel 1 goto err 

rem Поиск существующего текста в файле
%findtext% ReadMe.txt Project > "%TEMP%\output1.txt"
if errorlevel 1 goto err
fc "%TEMP%\output1.txt" readme-Project.txt
if errorlevel 1 goto err

rem Поиск текста, встречающегося на нескольких строках
%findtext% ReadMe.txt findtext > "%TEMP%\output1.txt"
if errorlevel 1 goto err
fc "%TEMP%\output1.txt" readme-findtext.txt
if errorlevel 1 goto err

rem Поиск несуществующего текста в файле
%findtext% ReadMe.txt Kozlovsky
if not errorlevel 1 goto err

rem TODO: написать тест, проверяющий, что искомая строка не может быть пустой
rem программа должрна вывести в этом случае сообщение в output

rem Проверка на то, что искомая строка не может быть пустой
%findtext% ReadMe.txt "" > "%TEMP%\output1.txt"
if not errorlevel 1 goto err
fc "%TEMP%\output1.txt" readme-emptyneedle.txt
if errorlevel 1 goto err

rem TODO: написать тест, проверяющий работу программы, когда входной файл открыть не удалось
rem программа должна сообщить об ошибке

rem Проверка, когда входной файл открыть не удалось
%findtext% NotExist.txt findtext > "%TEMP%\output1.txt"
if not errorlevel 1 goto err
fc "%TEMP%\output1.txt" readme-notexist.txt
if errorlevel 1 goto err

echo Program testing succeeded
exit /b 0

:err
echo Program testing failed
exit /b 1

