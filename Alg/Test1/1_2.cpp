#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iomanip>

using namespace std;

void insertionSort(int* arr, int n,
                   long long& comparisons,
                   long long& moves){
    comparisons = 0;
    moves = 0;

    for (int i = 1; i < n; i++){
        int key = arr[i];
        moves++;
        int j = i - 1;

        while (j >= 0){
            comparisons++;
            if (arr[j] > key){
                arr[j + 1] = arr[j];
                moves++;
                j--;
            }
            else
                break;
        }

        arr[j + 1] = key;
        moves++;
    }
}

int main(){
    srand(time(0));

    int n = 200000;
    int* arr = new int[n];

    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100;

    long long comparisons;
    long long moves;

    auto start = chrono::high_resolution_clock::now();

    insertionSort(arr, n, comparisons, moves);

    auto stop = chrono::high_resolution_clock::now();

    double time_ms =
        chrono::duration<double, milli>(stop - start).count();

    cout << fixed << setprecision(3);

    cout << "n\tTime(ms)\tCn\tMn\tTn" << endl;
    cout << n << "\t"
         << time_ms << "\t"
         << comparisons << "\t"
         << moves << "\t"
         << comparisons + moves << endl;

    delete[] arr;

    return 0;
}