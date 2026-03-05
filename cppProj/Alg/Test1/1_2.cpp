#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

void selectionSort(int* arr, int n,
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

int main(){
    srand(time(0));

    int n = 10;
    int* arr = new int[n];

    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100;

    cout << "Исходный массив:" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    long long comparisons;
    long long moves;

    auto start = chrono::high_resolution_clock::now();

    selectionSort(arr, n, comparisons, moves);

    auto stop = chrono::high_resolution_clock::now();

    double time_ms =
        chrono::duration<double, milli>(stop - start).count();

    cout << "Отсортированный массив:" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    cout << "Сравнения: " << comparisons << endl;
    cout << "Перемещения: " << moves << endl;
    cout << "Суммарно: " << comparisons + moves << endl;
    cout << "Время (мс): " << time_ms << endl;

    delete[] arr;

    return 0;
}
