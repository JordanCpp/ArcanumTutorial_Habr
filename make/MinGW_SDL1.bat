
"C:\Downloads\codeblocks-8.02mingw-setup\MinGW\bin\g++" -Wall -Wextra -std=c++98 -O2 -static -s -o MinGW_SDL1 ^
-I..\Arcanum\Shared ^
-I..\Pollux\Shared  ^
-I..\Pollux\SDL1  ^
-I..\dependencies\SDL-1.2.15\include ^
-L..\dependencies\SDL-1.2.15\lib\x86 ^
..\Pollux\SDL1\Pollux\Events\*.cpp ^
..\Pollux\SDL1\Pollux\Graphics\*.cpp  ^
..\Pollux\Shared\Pollux\Graphics\*.cpp  ^
..\main.cpp ^
..\Arcanum\Shared\Arcanum\Game\*.cpp ^
-lSDLmain -lSDL

pause