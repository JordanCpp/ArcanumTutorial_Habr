call "C:\VC6\Microsoft Visual Studio\VC98\Bin\VCVARS32.BAT"

cl /O2 /GX /MT -FeVC6_SDL1.exe  ^
/I..\Arcanum\Shared ^
/I..\Pollux\Shared  ^
/I..\Pollux\SDL1  ^
/I..\dependencies\SDL-devel-1.2.14-VC6\include ^
..\Pollux\SDL1\Pollux\Events\*.cpp ^
..\Pollux\SDL1\Pollux\Graphics\*.cpp  ^
..\Pollux\Shared\Pollux\Graphics\*.cpp  ^
..\main.cpp ^
..\Arcanum\Shared\Arcanum\Game\*.cpp ^
/link /LIBPATH:"..\dependencies\SDL-devel-1.2.14-VC6\lib" SDLmain.lib SDL.lib

del *.obj

pause
