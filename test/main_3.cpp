#include "../include/ArrayVector.hpp"
#include "../include/MergeSort.hpp"
#include "../include/QuickSort.hpp"
#include "../include/HeapSort.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>
#include <string>

void generateRandomDataset(ArrayVector& dataset, int n) {
    for (int i = 0; i < n; i++) {
        int key = rand() % 100;
        dataset.insert(i, { key, "data" + std::to_string(i) });
    }
}

void measureTime(const std::string& sortName, ArrayVector& dataset, void (*sortFunc)(ArrayVector&, int, int), std::ofstream& resultsFile) {
    auto start = std::chrono::high_resolution_clock::now();
    sortFunc(dataset, 0, dataset.size() - 1);
    auto end = std::chrono::high_resolution_clock::now();

    double elapsedTime = std::chrono::duration<double, std::milli>(end - start).count();

    // 파일에 쓰기
    resultsFile << sortName << " " << elapsedTime << "\n";
    // 터미널 출력
    std::cout << sortName << " took " << elapsedTime << " ms" << std::endl;
}

void measureHeapSortTime(const std::string& sortName, ArrayVector& dataset, std::ofstream& resultsFile) {
    auto start = std::chrono::high_resolution_clock::now();
    heapSort(dataset);
    auto end = std::chrono::high_resolution_clock::now();

    double elapsedTime = std::chrono::duration<double, std::milli>(end - start).count();

    // 파일에 쓰기
    resultsFile << sortName << " " << elapsedTime << "\n";
    // 터미널 출력
    std::cout << sortName << " took " << elapsedTime << " ms" << std::endl;
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    int datasetSizes[] = { 10, 100, 1000, 10000 };

    std::ofstream resultsFile("./data/results.txt");
    if (!resultsFile) {
        std::cerr << "Error: Could not open results.txt for writing\n";
        return 1;
    }

    for (int n : datasetSizes) {

        std::cout << "\nDataset size: " << n << "\n";

        resultsFile << "Dataset size:" << n << "\n";

        ArrayVector dataset;
        generateRandomDataset(dataset, n);
        ArrayVector copy = dataset;

        // MergeSort
        copy = dataset;
        measureTime("MergeSort", copy, mergeSort, resultsFile);

        // QuickSort
        copy = dataset;
        measureTime("QuickSort", copy, quickSort, resultsFile);

        // HeapSort
        copy = dataset;
        measureHeapSortTime("HeapSort", copy, resultsFile);
    }

    resultsFile.close();
    return 0;
}
