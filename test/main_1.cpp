#include "../include/HeapSort.hpp"
#include "../include/MergeSort.hpp"
#include "../include/QuickSort.hpp"
#include "../include/HeapSort.hpp"
#include <iostream>

void generateSmallDataset(ArrayVector& dataset) {
    dataset.insert(0, { 5, "data1" });
    dataset.insert(1, { 2, "data2" });
    dataset.insert(2, { 9, "data3" });
    dataset.insert(3, { 1, "data4" });
    dataset.insert(4, { 7, "data5" });
}

void printDataset(const ArrayVector& dataset) {
    for (int i = 0; i < dataset.size(); i++) {
        std::cout << "<" << dataset[i].first << ", " << dataset[i].second << "> ";
    }
    std::cout << std::endl;
}

int main() {
    ArrayVector dataset;
    generateSmallDataset(dataset);

    std::cout << "Original dataset:" << std::endl;
    printDataset(dataset);

    ArrayVector copy = dataset;

    // MergeSort
    mergeSort(copy, 0, copy.size() - 1);
    std::cout << "Merge Sorted:" << std::endl;
    printDataset(copy);

    // QuickSort
    copy = dataset;
    quickSort(copy, 0, copy.size() - 1);
    std::cout << "Quick Sorted:" << std::endl;
    printDataset(copy);

    // HeapSort
    copy = dataset;
    heapSort(copy);
    std::cout << "Heap Sorted:" << std::endl;
    printDataset(copy);

    return 0;
}