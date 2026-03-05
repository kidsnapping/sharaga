#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

void bubbleSort(int* arr, int n, long long& comparisons, long long& moves){
    comparisons = 0;
    moves = 0;

    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - 1 - i; j++){
            comparisons++;
            if (arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
                moves += 3;
            }
        }
    }
}

int main(){
    srand(time(0));

    int n = 5000;
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

    bubbleSort(arr, n, comparisons, moves);

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