//
// Created by Patryk on 27.05.2024.
//
#include <chrono>
#include "../header/MainMenu.h"
int choice;

MainMenu::MainMenu() : intArray(1), floatArray(0), charArray(0) {
}

void MainMenu::startMenu() {
    std::cout << "Choose test type:" << std::endl;
    std::cout << "1. Algorithm correctness test" << std::endl;
    std::cout << "2. Test for report" << std::endl;
    std::cout << "3. Test for specific scenario" << std::endl;
    choice = getChoice();

    switch (choice) {
        case 1:
            testCorrectness(); // Wywołanie funkcji testującej poprawność algorytmu
            break;
        case 2:
            std::cout << "Report Test Procedure Starting!:" << std::endl;
            std::cout << "1: Continue" << std::endl;
            std::cout << "2: End" << std::endl;
            std::cin >> choice;

            if(choice == 1){
                testForReport(); // Wywołanie funkcji testującej raport
            }
            break;
        case 3:
            testSpecificScenario(); // Wywołanie funkcji testującej konkretny scenariusz tablicy
            break;
        default:
            std::cerr << "Invalid choice!" << std::endl;
            break;
    }
}

void MainMenu::testSpecificScenario() {
}



template<typename T>
void MainMenu::beginSortingForSpecificScenario(const DynamicArray<T>& initialArray, const std::string& type, int size) {
}



void MainMenu::testCorrectness() {
    std::cout << "Choose:" << std::endl;
    std::cout << "1. Form File" << std::endl;
    std::cout << "2. Generate your self" << std::endl;
    choice = getChoice();

    switch (choice) {
        case 1:{
            testCorrectnessFile();
            break;
        }
        case 2:{
            testCorrectnessGenerateYourSelf();
            break;
        }
        default:
            std::cerr << "Invalid choice!" << std::endl;
            break;
    }
}


void MainMenu::testCorrectnessFile() {
}


void MainMenu::testCorrectnessGenerateYourSelf() {
}

template<typename T>
DynamicArray<T> MainMenu::generateRandomArray(int size, int min, int max) {

}

template<typename T>
DynamicArray<T> MainMenu::loadArrayFromFile(const std::string& filename) {

}

int MainMenu::getChoice() {
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    std::cout << "\n=------------=\n";
    return choice;
}

std::string MainMenu::chooseFileName(){
    std::string filename;
    std::cout << "Enter file name: ";
    std::cin >> filename;

    std::cout << "\n=------------=\n";
    return filename;
}

template<typename T>
void MainMenu::beginSortingCorectness(const DynamicArray<T>& initialArray){

}

template<typename T>
void MainMenu::sortingCheck(const DynamicArray<T>& initialArray) {

}


void MainMenu::testForReport() {

}

template<typename T>
void MainMenu::beginSortingForReportInsertion(const DynamicArray<T>& initialArray, const std::string& type, int size) {

}

template<typename T>
void MainMenu::beginSortingForReport(const DynamicArray<T>& initialArray, const std::string& type, int size) {

}

void MainMenu::measureAndSaveSortingTime(int size, const std::string& type, const std::string& algorithmName, std::chrono::duration<double> elapsedTime) {
    std::ofstream file(type + "_"+ algorithmName + "Times.csv", std::ios_base::app);
    if (file.is_open()) { // Sprawdzenie czy plik został otwarty poprawnie
        file << elapsedTime.count()<< ";" << size << std::endl; // Zapis czasu sortowania oraz rozmiaru tablicy
        file.close(); // Zamknięcie pliku
    } else {
        std::cerr << "Unable to open file for writing." << std::endl; // Komunikat o niepowodzeniu otwarcia pliku
    }
}
