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
..\main.cpp ^
..\Arcanum\Shared\Arcanum\Game\*.cpp ^
-lSDL2main -lSDL2

pause