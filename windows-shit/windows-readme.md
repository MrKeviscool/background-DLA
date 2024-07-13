this thing generates a random background based on a referance image, % of pixels to add and your colours of choice. it also has an option to automaticly set it as your background AANDD it can run at startup so you have a new one every time

just want to see what it makes without it changing your background or changing default settings?
just double click bggen.exe. it will use default settings and put the output in the dlaimgs folder

want to see it change your background? 
start 'run.bat'

want to to change settings?
open 'run.bat' in notepad and change the settings. in the ARGS= part

if you have 'installed' it so it runs when you start your laptop (next question), re-run the install script as admin to apply changes.

TO AUTOMATICLY RUN AND CHANGE YOUR BACKGROUND AT STARTUP:
run "install_SETUP.bat" as admin (right-click, run as admin)



changing the size of the input image ("./dlaimgs/ref.png") changes how many pixels are simulated. increasing the size does increase the simulation time. you can make your own referance images if you want;
black isnt a wall and everything else is
