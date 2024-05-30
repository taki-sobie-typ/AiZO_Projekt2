//
// Created by Patryk on 27.05.2024.
//
#ifndef MAINMENU_H
#define MAINMENU_H

#include <iostream>
#include <string>
#include <chrono>
//#include "DynamicArray.h"
#include <fstream> // Do operacji na plikach
#include <algorithm> // Do używania algorytmów standardowych


class MainMenu {
public:
    MainMenu(); // Konstruktor

    ~MainMenu() = default; // Destruktor

    void startMenu(); // Metoda rozpoczynająca działanie menu

private:
    // Metody pomocnicze
    void testCorrectness();
    void testCorrectnessFile();
    void testCorrectnessGenerateRandom();
    void testForReport();

    // Metoda statyczna do wyboru nazwy pliku
    static std::string chooseFileName();

    // Metoda statyczna do pomiaru i zapisu czasu sortowania
    static void measureAndSaveSortingTime(int size, int density, const std::string& type, const std::string& algorithmName, std::chrono::duration<double> elapsedTime);

    // Metoda statyczna do pobrania wyboru użytkownika
    static int getChoice();
};

#endif // MAINMENU_H
