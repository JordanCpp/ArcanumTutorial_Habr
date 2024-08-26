call "C:\VC6\Microsoft Visual Studio\VC98\Bin\VCVARS32.BAT"

cl /O2 /GX /MT -FeVC6_SDL1.exe  ^
/I..\Arcanum\Shared ^
/I..\Pollux\Shared  ^
/I..\Pollux\SDL1  ^
/I..\Pollux\Platforms\Windows ^
/I..\dependencies\SDL-devel-1.2.14-VC6\include ^
..\Pollux\Platforms\Windows\Pollux\Common\*.cpp ^
..\Pollux\SDL1\Pollux\Events\*.cpp ^
..\Pollux\SDL1\Pollux\Graphics\*.cpp  ^
..\Pollux\Shared\Pollux\Graphics\*.cpp  ^
..\Pollux\Shared\Pollux\Loaders\*.cpp  ^
..\Pollux\Shared\Pollux\Readers\*.cpp  ^
..\Pollux\Shared\Pollux\Common\*.cpp  ^
..\main.cpp ^
..\Arcanum\Shared\Arcanum\Formats\*.cpp ^
..\Arcanum\Shared\Arcanum\Formats\Art\*.cpp ^
..\Arcanum\Shared\Arcanum\Formats\Dat\*.cpp ^
..\Arcanum\Shared\Arcanum\Game\*.cpp ^
..\Arcanum\Shared\Arcanum\Managers\*.cpp ^
..\dependencies\zlib\adler32.c ^
..\dependencies\zlib\compress.c ^
..\dependencies\zlib\crc32.c ^
..\dependencies\zlib\deflate.c ^
..\dependencies\zlib\gzclose.c ^
..\dependencies\zlib\gzlib.c ^
..\dependencies\zlib\gzread.c ^
..\dependencies\zlib\gzwrite.c ^
..\dependencies\zlib\inflate.c ^
..\dependencies\zlib\infback.c ^
..\dependencies\zlib\inftrees.c ^
..\dependencies\zlib\inffast.c ^
..\dependencies\zlib\trees.c ^
..\dependencies\zlib\uncompr.c ^
..\dependencies\zlib\zutil.c ^
/I..\dependencies\zlib ^
/link /LIBPATH:"..\dependencies\SDL-devel-1.2.14-VC6\lib" SDLmain.lib SDL.lib

del *.obj

pause
