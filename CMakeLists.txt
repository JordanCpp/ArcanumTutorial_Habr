
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

include_directories("Pollux/SDL2")
file(GLOB_RECURSE POLLUX_SOURCES "Pollux/SDL2/*.cpp")

include_directories("Pollux/Shared")
file(GLOB_RECURSE SHARED_SOURCES "Pollux/Shared/*.cpp")

include_directories("Arcanum/Shared")
file(GLOB_RECURSE ARCANUM_SOURCES "Arcanum/Shared/*.cpp")

add_executable(Game "main.cpp" ${POLLUX_SOURCES} ${SHARED_SOURCES} ${ARCANUM_SOURCES})
target_link_libraries(Game ${SDL2_LIBRARIES})
