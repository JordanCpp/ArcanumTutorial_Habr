
"C:\Downloads\codeblocks-8.02mingw-setup\MinGW\bin\g++" -Wall -Wextra -std=c++98 -O2 -static -s -o MinGW_SDL1 ^
-I..\Arcanum\Shared ^
-I..\Pollux\Shared  ^
-I..\Pollux\SDL1  ^
-I..\Pollux\Platforms\Windows ^
-I..\dependencies\SDL-1.2.15\include ^
-L..\dependencies\SDL-1.2.15\lib\x86 ^
..\Pollux\Platforms\Windows\Pollux\Common\*.cpp ^
..\Pollux\SDL1\Pollux\Events\*.cpp ^
..\Pollux\SDL1\Pollux\Graphics\*.cpp  ^
..\Pollux\Shared\Pollux\Common\*.cpp  ^
..\Pollux\Shared\Pollux\Graphics\*.cpp  ^
..\Pollux\Shared\Pollux\Loaders\*.cpp  ^
..\Pollux\Shared\Pollux\Readers\*.cpp  ^
..\main.cpp ^
..\Arcanum\Shared\Arcanum\Common\*.cpp ^
..\Arcanum\Shared\Arcanum\Graphics\*.cpp ^
..\Arcanum\Shared\Arcanum\Formats\*.cpp ^
..\Arcanum\Shared\Arcanum\Formats\Art\*.cpp ^
..\Arcanum\Shared\Arcanum\Formats\Dat\*.cpp ^
..\Arcanum\Shared\Arcanum\Game\*.cpp ^
..\Arcanum\Shared\Arcanum\Managers\*.cpp ^
-I..\dependencies\zlib ^
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
-lSDLmain -lSDL

pause