
#set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_STANDARD 23)
#set(CMAKE_CXX_STANDARD 26)

if (MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
    add_definitions(-D_CRT_NONSTDC_NO_DEPRECATE)  
endif()

if (WIN32)
    cmake_minimum_required(VERSION 2.9)

    set(SDL2_INCLUDE_DIRS "dependencies/SDL2-2.30.3/include")
    set(SDL2_LIBRARIES SDL2main SDL2)

    if(CMAKE_SIZEOF_VOID_P EQUAL 8)
        link_directories("dependencies/SDL2-2.30.3/lib/x64")
    elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
        link_directories("dependencies/SDL2-2.30.3/lib/x86")
    endif()
else()
    find_package(SDL2 REQUIRED)
endif()

include_directories(${SDL2_INCLUDE_DIRS})

include_directories("dependencies/zlib")

file(GLOB ZLIB_SOURCES 
"dependencies/zlib/adler32.c"
"dependencies/zlib/compress.c"
"dependencies/zlib/crc32.c"
"dependencies/zlib/deflate.c"
"dependencies/zlib/gzclose.c"
"dependencies/zlib/gzlib.c"
"dependencies/zlib/gzread.c"
"dependencies/zlib/gzwrite.c"
"dependencies/zlib/inflate.c"
"dependencies/zlib/infback.c"
"dependencies/zlib/inftrees.c"
"dependencies/zlib/inffast.c"
"dependencies/zlib/trees.c"
"dependencies/zlib/uncompr.c"
"dependencies/zlib/zutil.c")

add_library(zlib ${ZLIB_SOURCES})

include_directories("litecpp")
file(GLOB_RECURSE LITECPP_SOURCES "litecpp/source/*.cpp" ${LITECPP_SOURCES})
add_library(litecpp ${LITECPP_SOURCES})

include_directories("Pollux/SDL2")
include_directories("Pollux/Shared")

if (WIN32)
    include_directories("Pollux/Platforms/Windows")
    file(GLOB_RECURSE POLLUX_PLATFORM_SOURCES "Pollux/Platforms/Windows/*.cpp")
else()
    include_directories("Pollux/Platforms/Linux")
    file(GLOB_RECURSE POLLUX_PLATFORM_SOURCES "Pollux/Platforms/Linux/*.cpp")
endif()

file(GLOB_RECURSE POLLUX_SOURCES "Pollux/SDL2/*.cpp" "Pollux/Shared/*.cpp" ${POLLUX_PLATFORM_SOURCES})
add_library(Pollux ${POLLUX_SOURCES})
target_link_libraries(Pollux ${SDL2_LIBRARIES})

include_directories("Arcanum/Shared")
file(GLOB_RECURSE ARCANUM_SOURCES "Arcanum/Shared/*.cpp")
add_library(Arcanum ${ARCANUM_SOURCES})
target_link_libraries(Arcanum Pollux zlib litecpp)

add_executable(Game "main.cpp")
target_link_libraries(Game Arcanum)

if (WIN32)
    if(CMAKE_SIZEOF_VOID_P EQUAL 8)
        file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/SDL2-2.30.3/lib/x64/SDL2.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)
    elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
        file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/SDL2-2.30.3/lib/x86/SDL2.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)
    endif()
endif()

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/data      DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/TestFiles DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Tests)

add_subdirectory(Tests)
