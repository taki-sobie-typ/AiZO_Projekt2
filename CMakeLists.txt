cmake_minimum_required(VERSION 3.28)
project(AiZO_Projekt2)

set(CMAKE_CXX_STANDARD 17)
MATH(EXPR stack_size "16 * 1024 * 1024")
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,${stack_size}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--stack,16777216")

#set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(AiZO_Projekt2 main.cpp
        header/MainMenu.h
        header/MainMenu.h
        source/MainMenu.cpp
        source/MainMenu.cpp
        header/WeightedDirectedGraphMatrix.h
        source/WeightedDirectedGraphMatrix.cpp
        header/WeightedDirectedGraphList.h
        source/WeightedDirectedGraphList.cpp
        header/PrimMatrixMST.h
        source/PrimMatrixMST.cpp
        header/PrimListMST.h
        source/PrimListMST.cpp)
