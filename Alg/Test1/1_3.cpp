#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iomanip>

using namespace std;

// по возрастанию
void selectionSortUp(int* arr, int n,
                   long long& comparisons,
                   long long& moves){
    comparisons = 0;
    moves = 0;

    for (int i = 0; i < n - 1; i++){
        int minIndex = i;

        for (int j = i + 1; j < n; j++){
            comparisons++;
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        if (minIndex != i){
            swap(arr[i], arr[minIndex]);
            moves += 3;
        }
    }
}
// по убыванию
void selectionSortDown(int* arr, int n, 
                             long long& comparisons, 
                             long long& moves) {
    comparisons = 0;
    moves = 0;

    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i; 

        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] > arr[maxIndex]) { 
                maxIndex = j;
            }
        }

        if (maxIndex != i) {
            swap(arr[i], arr[maxIndex]);
            moves += 3;
        }
    }
}

int main(){
    srand(time(0));

    int n = 500;
    int* arr = new int[n];

    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100;

    long long comparisons;
    long long moves;

    auto start = chrono::high_resolution_clock::now();

    selectionSortDown(arr, n, comparisons, moves);

    auto stop = chrono::high_resolution_clock::now();

    double time_ms =
        chrono::duration<double, milli>(stop - start).count();

    cout << fixed << setprecision(8);

    cout << "n\tTime(ms)\tCn\tMn\tTn" << endl;
    cout << n << "\t"
         << time_ms << "\t"
         << comparisons << "\t"
         << moves << "\t"
         << comparisons + moves << endl;

    delete[] arr;

    return 0;
}