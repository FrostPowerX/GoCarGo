@echo off

echo %1 Solution Dir
echo %2 Target Dir
echo "%3" Target Name
echo "%4" Lib Name
echo %5

if "%6"=="1" (
    echo Copying and packing
    del "%~1bin\Release\%~3.pdb"
    xcopy "%~1res" "%~2res" /i /y /s
    copy "%~1libs\%~4\bin\openal32.dll" "%~2" /y
    copy "%~1libs\%~4\bin\sfml-audio-2.dll" "%~2" /y
    copy "%~1libs\%~4\bin\sfml-graphics-2.dll" "%~2" /y
    copy "%~1libs\%~4\bin\sfml-system-2.dll" "%~2" /y
    copy "%~1libs\%~4\bin\sfml-window-2.dll" "%~2" /y
    tar --create --file="%~3.zip" -C "%~1bin\Release" .
) ELSE (
    xcopy "%~1res" "%~2res" /i /y /s
    copy "%~1libs\%~4\bin\openal32.dll" "%~2" /y
    copy "%~1libs\%~4\bin\sfml-audio-d-2.dll" "%~2" /y
    copy "%~1libs\%~4\bin\sfml-graphics-d-2.dll" "%~2" /y
    copy "%~1libs\%~4\bin\sfml-system-d-2.dll" "%~2" /y
    copy "%~1libs\%~4\bin\sfml-window-d-2.dll" "%~2" /y
)