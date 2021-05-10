@echo off

IF NOT EXIST "./build" (
    GOTO EXIT
) ELSE (
    GOTO INSTALL_STUFF
)

:EXIT
EXIT 1

:START_BACKEND
timeout /t 10 /nobreak
cd ./backend
node ./build/Index.js

GOTO START_BACKEND

:INSTALL_STUFF
start cmd /c "install_dependencies.bat"
GOTO START_BACKEND