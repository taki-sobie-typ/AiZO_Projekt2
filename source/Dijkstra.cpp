#include "../header/Dijkstra.h"
#include <iostream>
#include <limits>
#include <chrono>

using namespace std;

void Dijkstra::uruchomDlaListy(const ListaSasiedztwa& graf, int start) {
    auto start_time = chrono::high_resolution_clock::now(); // Start pomiaru czasu

    size_t liczbaWierzcholkow = graf.pobierzLiczbeWierzcholkow();
    int* odleglosc = new int[liczbaWierzcholkow];
    bool* odwiedzone = new bool[liczbaWierzcholkow];

    for (size_t i = 0; i < liczbaWierzcholkow; ++i) {
        odleglosc[i] = numeric_limits<int>::max();
        odwiedzone[i] = false;
    }

    odleglosc[start] = 0;

    for (size_t count = 0; count < liczbaWierzcholkow - 1; ++count) {
        int min = numeric_limits<int>::max(), minIndex;

        for (size_t v = 0; v < liczbaWierzcholkow; ++v) {
            if (!odwiedzone[v] && odleglosc[v] <= min) {
                min = odleglosc[v];
                minIndex = v;
            }
        }

        int u = minIndex;
        odwiedzone[u] = true;

        const Krawedz* krawedz = graf.getSasiedzi(u);
        while (krawedz != nullptr) {
            int v = krawedz->koniec;
            if (!odwiedzone[v] && odleglosc[u] != numeric_limits<int>::max() && odleglosc[u] + krawedz->wartosc < odleglosc[v]) {
                odleglosc[v] = odleglosc[u] + krawedz->wartosc;
            }
            krawedz = krawedz->nastepna;
        }
    }

    auto stop_time = chrono::high_resolution_clock::now(); // Koniec pomiaru czasu
    auto duration = chrono::duration_cast<chrono::microseconds>(stop_time - start_time);
    cout << "Czas dzialania algorytmu Dijkstry (Lista Sasiedztwa): " << duration.count() << " mikrosekund" << endl;

    for (size_t i = 0; i < liczbaWierzcholkow; ++i) {
        cout << "Odleglosc od " << start << " do " << i << " wynosi " << odleglosc[i] << endl;
    }

    delete[] odleglosc;
    delete[] odwiedzone;
}

void Dijkstra::uruchomDlaMacierzy(const MacierzIncydencji& graf, int start) {
    auto start_time = chrono::high_resolution_clock::now(); // Start pomiaru czasu

    size_t liczbaWierzcholkow = graf.pobierzLiczbeWierzcholkow();
    int* odleglosc = new int[liczbaWierzcholkow];
    bool* odwiedzone = new bool[liczbaWierzcholkow];

    for (size_t i = 0; i < liczbaWierzcholkow; ++i) {
        odleglosc[i] = numeric_limits<int>::max();
        odwiedzone[i] = false;
    }

    odleglosc[start] = 0;

    for (size_t count = 0; count < liczbaWierzcholkow - 1; ++count) {
        int min = numeric_limits<int>::max(), minIndex;

        for (size_t v = 0; v < liczbaWierzcholkow; ++v) {
            if (!odwiedzone[v] && odleglosc[v] <= min) {
                min = odleglosc[v];
                minIndex = v;
            }
        }

        int u = minIndex;
        odwiedzone[u] = true;

        for (size_t v = 0; v < liczbaWierzcholkow; ++v) {
            int waga = graf.pobierzWage(u, v);
            if (waga != -1 && !odwiedzone[v] && odleglosc[u] != numeric_limits<int>::max() && odleglosc[u] + waga < odleglosc[v]) {
                odleglosc[v] = odleglosc[u] + waga;
            }
        }
    }

    auto stop_time = chrono::high_resolution_clock::now(); // Koniec pomiaru czasu
    auto duration = chrono::duration_cast<chrono::microseconds>(stop_time - start_time);
    cout << "Czas dzialania algorytmu Dijkstry (Macierz Incydencji): " << duration.count() << " mikrosekund" << endl;

    for (size_t i = 0; i < liczbaWierzcholkow; ++i) {
        cout << "Odleglosc od " << start << " do " << i << " wynosi " << odleglosc[i] << endl;
    }

    delete[] odleglosc;
    delete[] odwiedzone;
}
