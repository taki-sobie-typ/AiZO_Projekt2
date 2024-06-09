cmake_minimum_required(VERSION 3.27)
project(AiZO_Projekt_2)

set(CMAKE_CXX_STANDARD 23)

add_executable(
        AiZO_Projekt_2 main.cpp
        source/CzytnikGrafow.cpp
        source/Dijkstra.cpp
        source/GeneratorGrafow.cpp
        source/GrafManager.cpp
        source/ListaSasiedztwa.cpp
        source/MacierzIncydencji.cpp
        source/Menu.cpp
        source/Prim.cpp
        header/CzytnikGrafow.h
        header/Dijkstra.h
        header/GeneratorGrafow.h
        header/GrafManager.h
        header/ListaSasiedztwa.h
        header/MacierzIncydencji.h
        header/Menu.h
        header/Prim.h
)
