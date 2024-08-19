call "C:\Downloads\codeblocks-12.11mingw-setup\MinGW\mingwvars.bat"

g++ -Wall -Wextra -pedantic -O2 -std=c++11 -static -s -o MinGW_SDL2 ^
-I..\Arcanum\Shared ^
-I..\Pollux\Shared  ^
-I..\Pollux\SDL2  ^
-I..\dependencies\SDL2-2.30.3\include ^
-L..\dependencies\SDL2-2.30.3\lib\x86 ^
..\Pollux\SDL2\Pollux\Events\*.cpp ^
..\Pollux\SDL2\Pollux\Graphics\*.cpp  ^
..\Pollux\Shared\Pollux\Graphics\*.cpp  ^
..\Pollux\Shared\Pollux\Loaders\*.cpp  ^
..\main.cpp ^
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
-lSDL2main -lSDL2

pause