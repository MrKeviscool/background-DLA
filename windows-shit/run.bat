@echo off

:: these are already the default options but i left them in so its easy to edit. the '10' is the % of pixels to simulate. the numbers after --setcol were the hex colours you chose without the #. the -s is set as back ground
:: WARNING, -s changes your background

::      %to fill        ::hex colours to set      -s = set background
SET ARGS=10 --setcol aa84bf 84bf88 735648 734857 -s


::dw about this stuff
if exist "%programdata%\bggen\bggen.exe" goto progfles

start "generating bg..." bggen.exe %ARGS%
goto end

:progfles
start "generating bg..." /d "%programdata%\bggen" /min bggen.exe %ARGS%
:end