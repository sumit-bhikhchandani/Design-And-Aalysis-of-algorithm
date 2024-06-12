#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace std::chrono;

// Merge Sort implementation
void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r)
        return;

    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

// Quick Sort implementation
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to generate random array
void generateRandomArray(vector<int>& arr, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr.push_back(rand() % 1000); // Generates random numbers between 0 and 999
    }
}

int main() {
    vector<int> arr1, arr2;
    vector<int> sizes = {10000, 50000, 100000, 200000}; // Example array sizes

    for (int n : sizes) {
        cout << "Array size: " << n << endl;

        // Generate random arrays
        generateRandomArray(arr1, n);
        arr2 = arr1;

        // Measure time taken by Merge Sort
        auto startMerge = high_resolution_clock::now();
        mergeSort(arr1, 0, arr1.size() - 1);
        auto stopMerge = high_resolution_clock::now();
        auto durationMerge = duration_cast<milliseconds>(stopMerge - startMerge);
        cout << "Time taken by Merge Sort: " << durationMerge.count() << " milliseconds" << endl;

        // Measure time taken by Quick Sort
        auto startQuick = high_resolution_clock::now();
        quickSort(arr2, 0, arr2.size() - 1);
        auto stopQuick = high_resolution_clock::now();
        auto durationQuick = duration_cast<milliseconds>(stopQuick - startQuick);
        cout << "Time taken by Quick Sort: " << durationQuick.count() << " milliseconds" << endl;

        cout << endl;
    }

    return 0;
}
