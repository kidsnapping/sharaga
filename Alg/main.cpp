#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace chrono;

// -------------------- Глобальные счетчики --------------------
long long Cn;   // comparisons
long long Mn;   // moves
long long Tn;   // total = Cn + Mn

void resetCounters() {
    Cn = 0;
    Mn = 0;
    Tn = 0;
}

// -------------------- Заполнение массива --------------------

// 1. Случайное заполнение
void fillRandom(char* arr, int n, char minChar = 'a', char maxChar = 'z') {
    for (int i = 0; i < n; i++)
        arr[i] = minChar + rand() % (maxChar - minChar + 1);
}

// 2. Заполнение заданным значением
void fillWithValue(char* arr, int n, char value) {
    for (int i = 0; i < n; i++)
        arr[i] = value;
}

// 3. Заполнение значениями, не равными key
void fillWithoutKey(char* arr, int n, char key) {
    for (int i = 0; i < n; i++) {
        char value;
        do {
            value = 'a' + rand() % 26;
        } while (value == key);
        arr[i] = value;
    }
}

// -------------------- АЛГОРИТМ 1 --------------------
void delFirstMethod(char* x, int& n, char key) {
    int i = 0;

    while (i < n) {
        Cn++;
        if (x[i] == key) {
            for (int j = i; j < n - 1; j++) {
                x[j] = x[j + 1];
                Mn++;
            }
            n--;
        } else {
            i++;
        }
    }
    Tn = Cn + Mn;
}

// -------------------- АЛГОРИТМ 2 --------------------
void delSecondMethod(char* x, int& n, char key) {
    int j = 0;

    for (int i = 0; i < n; i++) {
        Cn++;
        if (x[i] != key) {
            x[j] = x[i];
            Mn++;
            j++;
        }
    }
    n = j;
    Tn = Cn + Mn;
}

// -------------------- ТЕСТ --------------------
void test(int n, char key, int mode) {

    char* arr1 = new char[n];
    char* arr2 = new char[n];

    // Три варианта заполнения
    switch (mode) {
        case 1: // все удаляются
            fillWithValue(arr1, n, key);
            break;

        case 2: // случайное заполнение
            fillRandom(arr1, n);
            break;

        case 3: // ни один не удаляется
            fillWithoutKey(arr1, n, key);
            break;
    }

    // Копирование для одинаковых условий
    for (int i = 0; i < n; i++)
        arr2[i] = arr1[i];

    cout << "\nРазмер массива: " << n << endl;

    // ---------- Алгоритм 1 ----------
    int n1 = n;
    resetCounters();

    auto start1 = high_resolution_clock::now();
    delFirstMethod(arr1, n1, key);
    auto stop1 = high_resolution_clock::now();

    duration<double, milli> time1 = stop1 - start1;

    cout << "Алгоритм 1:";
    cout << "Cn = " << Cn
         << "  Mn = " << Mn
         << "  Tn = " << Tn
         << "  Time = " << time1.count() << " ms\n";

    // ---------- Алгоритм 2 ----------
    int n2 = n;
    resetCounters();

    auto start2 = high_resolution_clock::now();
    delSecondMethod(arr2, n2, key);
    auto stop2 = high_resolution_clock::now();

    duration<double, milli> time2 = stop2 - start2;

    cout << "Алгоритм 2: ";
    cout << "Cn = " << Cn
         << "  Mn = " << Mn
         << "  Tn = " << Tn
         << "  Time = " << time2.count() << " ms\n";

    delete[] arr1;
    delete[] arr2;
}

// -------------------- MAIN --------------------
int main() {

    srand(time(0));

    char key = 'a';
    int sizes[] = {100, 200, 500, 1000, 2000, 5000, 10000};

    cout << "===== СЛУЧАЙ A: Все элементы удаляются =====\n";
    for (int n : sizes)
        test(n, key, 1);

    cout << "\n===== СЛУЧАЙ B: Случайное заполнение =====\n";
    for (int n : sizes)
        test(n, key, 2);

    cout << "\n===== СЛУЧАЙ C: Ни один элемент не удаляется =====\n";
    for (int n : sizes)
        test(n, key, 3);

    return 0;
}