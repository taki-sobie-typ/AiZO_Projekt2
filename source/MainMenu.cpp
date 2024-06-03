//
// Created by Patryk on 27.05.2024.
//

#include <chrono>
#include "../header/MainMenu.h"
#include "../header/WeightedDirectedGraphMatrix.h"
#include "../header/WeightedDirectedGraphList.h"
#include "../header/PrimMatrixMST.h"
#include "../header/PrimListMST.h"
#include "../header/DijkstraShortestPathMatrix.h"

int choice;

MainMenu::MainMenu(){
}

void MainMenu::startMenu() {
    std::cout << "Choose:" << std::endl;
    std::cout << "1. Algorithm Correctness" << std::endl;
    std::cout << "2. Test Report" << std::endl;
    choice = getChoice();

    switch (choice) {
        case 1:
            testCorrectness(); // Wywołanie funkcji testującej poprawność
            break;
        case 2:
            std::cout << "Report Test Procedure Starting!:" << std::endl;
            std::cout << "1: Continue" << std::endl;
            std::cout << "2: End" << std::endl;
            std::cin >> choice;

            if(choice == 1){
                testForReport(); // Wywołanie funkcji testującej do raportu
            }
            break;
        default:
            std::cerr << "Invalid choice!" << std::endl;
            break;
    }
}

void MainMenu::testCorrectness() {
    std::cout << "Choose:" << std::endl;
    std::cout << "1. Form File" << std::endl;
    std::cout << "2. Generate Random" << std::endl;
    choice = getChoice();

    switch (choice) {
        case 1:{
            testCorrectnessFile();
            break;
        }
        case 2:{
            testCorrectnessGenerateRandom();
            break;
        }
        default:
            std::cerr << "Invalid choice!" << std::endl;
            break;
    }
}

void MainMenu::testForReport() {
    //MATRIX PART


    // Create a graph with 6 vertices and 8 edges
    WeightedDirectedGraphMatrix graphMatrix(20);
    graphMatrix.generateRandomGraph(20);


    // Print the graph
    graphMatrix.printGraph();

    // Create DijkstraShortestPathMatrix object
    DijkstraShortestPathMatrix dijkstra(graphMatrix);

    // Find the shortest path from vertex 0 to vertex 5
    std::vector<int> path = dijkstra.findShortestPath(graphMatrix.getFirstVertex(), graphMatrix.getLastVertex());

    // Print the shortest path
    dijkstra.printShortestPath(path);

    // Create an instance of the PrimMST class
    PrimMatrixMST mst(graphMatrix);

    // Find the MST
    mst.findMST();

    // Print the MST
    mst.printMST();




    /*
    //LIST PART

    // Define the number of vertices for the graph
    //int vertices = 5;  // Number of vertices

    // Create an instance of the graph
    WeightedDirectedGraphList graphList(12);

    // Generate a random graph with a specified density (e.g., 50%)
    //int density = 50;
    graphList.generateRandomGraph(30);

    // Print the generated graph
    std::cout << "Generated Weighted Directed Graph:" << std::endl;
    graphList.printGraph();

    // Create an instance of PrimListMST with the graph object
    PrimListMST primListMST(graphList);

    // Find the Minimum Spanning Tree using Prim's algorithm
    primListMST.findMST();

    // Print the Minimum Spanning Tree
    std::cout << "Minimum Spanning Tree (MST) using Prim's Algorithm:" << std::endl;
    primListMST.printMST();
    */
}

void MainMenu::testCorrectnessFile() {
    chooseFileName();
}

void MainMenu::testCorrectnessGenerateRandom() {
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

void MainMenu::measureAndSaveSortingTime(int size, int density, const std::string& type, const std::string& algorithmName, std::chrono::duration<double> elapsedTime) {
    std::ofstream file(type + "_"+ algorithmName + "Times.csv", std::ios_base::app);
    if (file.is_open()) { // Sprawdzenie czy plik został otwarty poprawnie
        file << elapsedTime.count()<< ";" << size << ";" << density << std::endl; // Zapis czasu i innych parametrów
        file.close(); // Zamknięcie pliku
    } else {
        std::cerr << "Unable to open file for writing." << std::endl; // Komunikat o niepowodzeniu otwarcia pliku
    }
}
