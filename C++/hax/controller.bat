	@echo off
	color 4
	ECHO Welcome to the control room!
	ping 1.1.1.1 -n 1 -w 1500>nul
	cls
	color B
	ECHO     Made by mrwoofles705
	ping 1.1.1.1 -n 1 -w 1500>nul
	cls
	color 2
	ECHO version 0.321
	ping 1.1.1.1 -n 1 -w 1500>nul
	cls
	color 3
	:start
	cls
	
	SET /P _inputname= Please enter an input:
	IF "%_inputname%"=="starsector" GOTO :SS
	IF "%_inputname%"=="unturned" GOTO :UT
	IF "%_inputname%"=="GD" GOTO :Geometry_dash
	IF "%_inputname%"=="spam" GOTO :SteamSpam
	IF "%_inputname%"=="bles" GOTO :bubbles
	IF "%_inputname%"=="shutdown" GOTO :SD
	IF "%_inputname%"=="system" GOTO :SYS
	IF "%_inputname%"=="cpanel" GOTO :CONTROL_PANEL
	IF "%_inputname%"=="tmgr" GOTO :TASK_MANAGER
	IF "%_inputname%"=="skype" GOTO :SKYPE
	IF "%_inputname%"=="steam" GOTO :STEAM
	IF "%_inputname%"=="ghub" GOTO :GITHUB_DEKSTOP
	IF "%_inputname%"=="help" GOTO :HELP
	IF "%_inputname%"=="web_ghub" GOTO :GITHUB_WEB
	IF "%_inputname%"=="youtube" GOTO :YOUTUBE
	IF "%_inputname%"=="google" GOTO :GOOGLE
	IF "%_inputname%"=="I'm depressed" GOTO :ID
	IF "%_inputname%"=="the truth" GOTO :TT
	IF "%_inputname%"=="kill me" GOTO :KM
	IF "%_inputname%"=="change my name" GOTO :CUSTOMCOMMAND
	IF "%_inputname%"=="secfile" GOTO :SF
	
	::TO ADD A COMMAND MAKE A FOLDER WITH THE NAME CTRBATCOM AND ADD WHATEVER PROGRAM YOU WANT TO START IN THE FOLDER
	:CUSTOMCOMMAND
	cd C:\Program Files (x86)\CTRBATCOM\
	start your program name goes here
	ECHO add a comment here or just delete this line
	
	pause
	GOTO :start
	
	:: lists all the commands
	:HELP
	ECHO (I)don't type ; with the commands(I)
	ECHO starsector    ; starts starsector
	ECHO unturned      ; starts unturned
	ECHO GD            ; starts Geometry Dash
	ECHO bles          ; starts bubbles screensaver
	ECHO cpanel        ; opens control panel
	ECHO taskmgr       ; starts task manager
	ECHO skype         ; starts skype
	ECHO ghub          ; starts ghub (the program not the website)
	ECHO help          ; realeaves the your 
	ECHO               ; hedache with this program ;)
	ECHO               ; version 0.437
	ECHO web_ghub      ; sstarts you to the Git Hub website
	ECHO youtube       ; sstarts you to youtube
	ECHO google        ; sstarts you to the google website
	ECHO I'm depressed ;  gives you encouragement......
	ECHO secfile       ; type secfile then type the required password to open a secure file
	ECHO Give your ideas for other programs to start from this batch!
	
	ECHO Plz
	
	:KM
	start :: what does this do?

	pause
	GOTO :start
	
	:AUTISM
	start http://youhaveautism.com/
	
	pause
	GOTO :start
	
	:ENCOURAGEMENT
	echo Encouragement!
	start https://www.youtube.com/watch?v=KxGRhd_iWuE
	
	pause
	GOTO :start	

	pause
	GOTO :start
	
	::opens you to the google webpage
	:GOOGLE
	start https://www.google.com/
	sssssssssssssssssssssssssssssssssssssssssssssssssssssssss
	pause
	GOTO :start
	
	::sstarts you to youtube
	:YOUTUBE
	start https://www.youtube.com/
	
	pause
	GOTO :start
	
	:: sstarts you to the Git Hub website
	:GITHUB_WEB
	start https://github.com/
	
	pause
	GOTO :start
	
	::starts GitHub (I) replace wyatt with your user name of the computer or just the type where the file location of GitHub is (I)
	:GITHUB_DESKTOP
	cd C:\Users\wyatt\Desktop\
	start GitHub.appref-ms
	ECHO starting GitHub.....
	
	pause
	GOTO :start
	
	::starts steam
	:STEAM
	cd C:\Program Files (x86)\Steam
	start steam
	ECHO starting steam.....
	
	pause
	GOTO :start
	
	::opens skype
	:SKYPE
	cd C:\Program Files (x86)\Skype\Phone\
	start Skype.exe
	ECHO starting skype.....
	
	pause
	GOTO start
	
	::opens task manager
	:TASKMGR
	start taskmgr
	ECHO starting task manager.....
	
	pause
	GOTO :start
	
	::opens control panel. (I)Usefull when your at school
	:CONTROL_PANEL
	start control
	ECHO opening control panel
	
	pause
	GOTO :start
	
	
	::displays information about the current system.
	::(I) Usefull when your at school and access from the program 
	:: isn't accessable but the program isn't disabled.  
	:SYSTEM_INFO
	cd %windir%\system32\
	start msinfo32.exe
	ECHO displaying system info.....
	
	pause
	GOTO :start
	
	:: macks boobles :D
	:bubbles
	start %windir%/system32/bubbles.scr
	ECHO BUBBLES!!!!!
	
	pause
	GOTO :start
	
	::start SteamSpam(I)this is just for me :) (I)Unless you have this program, then you will just need to replace wyatt with your computeruser name
	:STEAMSPAM
	cd C:\users\wyatt\Desktop\
	start SteamSpam
	ECHO starting steam spam.....
	
	pause
	GOTO :start
	
	::start geometry dash
	:Geometry_dash
	cd C:\Program Files (x86)\Steam\steamapps\common\Geometry Dash\
	start GeometryDash
	ECHO starting GD.....
	
	pause 
	GOTO :start
	
	::start unturned
	:UT
	cd C:\Program Files (x86)\Steam\steamapps\common\Unturned\
	start unturned
	ECHO starting Unturned.....
	
	pause
	GOTO :start
	
	::start starsector
	:SS
	cd C:\Program Files (x86)\Fractal Softworks\Starsector\
	start starsector
	ECHO starting Starsector.....
	
	pause
	GOTO :start
	
	::aborts shutdown command
	:AB 
	shutdown /a
	
	GOTO start
	ECHO abort complete
	
	IF "%_inputname%"=="AB" GOTO :ABORT	
	::shuts down the current computer in 20 seconds
	
	:SD
	shutdown /s /t 20
	ping 1.1.1.1 -n 1 -w 1000>nul
	ECHO 10
	ping 1.1.1.1 -n 1 -w 1000>nul
	ECHO 9
	ping 1.1.1.1 -n 1 -w 1000>nul
	ECHO 8
	ping 1.1.1.1 -n 1 -w 1000>nul
	ECHO 7
	ping 1.1.1.1 -n 1 -w 1000>nul
	ECHO 6
	ping 1.1.1.1 -n 1 -w 1000>nul
	ECHO 5
	ping 1.1.1.1 -n 1 -w 1000>nul
	ECHO 4
	ping 1.1.1.1 -n 1 -w 1000>nul
	ECHO 3
	ping 1.1.1.1 -n 1 -w 1000>nul
	ECHO 2
	ping 1.1.1.1 -n 1 -w 10000>nul
	ECHO shuting down
	
	:: edit CHANGEME! to the password you want
	:SF
	cls 
	@ECHO OFF 
	title Folder Private 
	if EXIST "HTG Locker" goto UNLOCK 
	if NOT EXIST Private goto MDLOCKER 
	:CONFIRM 
	echo Are you sure you want to lock the folder(Y/N) 
	set/p "cho=>" 
	if %cho%==Y goto LOCK 
	if %cho%==y goto LOCK 
	if %cho%==n goto start 
	if %cho%==N goto start 
	echo Invalid choice. 
	goto CONFIRM 
	:LOCK 
	ren Private "HTG Locker" 
	attrib +h +s "HTG Locker" 
	echo Folder locked 
	goto start 
	:UNLOCK 
	echo Enter password to unlock folder 
	set/p "pass=>" 
	if NOT %pass%== CHANGEME! goto FAIL 
	attrib -h -s "HTG Locker" 
	ren "HTG Locker" Private 
	echo Folder Unlocked successfully 
	goto start 
	:FAIL 
	echo Invalid password 
	goto start 
	:MDLOCKER 
	md Private 
	echo Private created successfully 
	goto start
	