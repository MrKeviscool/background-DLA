::installs bg-gen to the right location to have it auto run

copy "%~dp0\run.bat" "%appdata%\Microsoft\Windows\Start Menu\Programs\Startup"
mkdir "%programdata%\bggen"
mkdir "%programdata%\bggen\dlaimgs"
copy "%~dp0\bggen.exe" "%programdata%\bggen"
copy "%~dp0\dlaimgs" "%programdata%\bggen\dlaimgs"
