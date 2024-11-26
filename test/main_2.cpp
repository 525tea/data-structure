#include "../include/ArrayVector.hpp"
#include "../include/MergeSort.hpp"
#include "../include/QuickSort.hpp"
#include "../include/HeapSort.hpp"
#include <iostream>

void generateStabilityTestDataset(ArrayVector& dataset) {
    dataset.insert(0, { 5, "data1" });
    dataset.insert(1, { 3, "data2" });
    dataset.insert(2, { 3, "data3" });
    dataset.insert(3, { 2, "data4" });
    dataset.insert(4, { 2, "data5" });
    dataset.insert(5, { 5, "data6" });
    dataset.insert(6, { 1, "data7" });
    dataset.insert(7, { 4, "data8" });
    dataset.insert(8, { 3, "data9" });
    dataset.insert(9, { 2, "data10" });
}

void printDataset(const ArrayVector& dataset) {
    for (int i = 0; i < dataset.size(); i++) {
        std::cout << "<" << dataset[i].first << ", " << dataset[i].second << "> ";
    }
    std::cout << std::endl;
}

int main() {
    ArrayVector dataset;
    generateStabilityTestDataset(dataset);

    std::cout << "Original dataset:" << std::endl;
    printDataset(dataset);

    ArrayVector copy = dataset;

    // MergeSort
    mergeSort(copy, 0, copy.size() - 1);
    std::cout << "Merge Sorted (Stability Test):" << std::endl;
    printDataset(copy);

    // QuickSort
    copy = dataset;
    quickSort(copy, 0, copy.size() - 1);
    std::cout << "Quick Sorted (Stability Test):" << std::endl;
    printDataset(copy);

    // HeapSort
    copy = dataset;
    heapSort(copy);
    std::cout << "Heap Sorted (Stability Test):" << std::endl;
    printDataset(copy);

    return 0;
}