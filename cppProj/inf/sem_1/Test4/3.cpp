#include <iostream>
#include <cmath>

int main() {
    const int size = 20;
    char A[size][size];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            A[i][j] = ' ';
        }
    }

    for (double x = -M_PI; x <= M_PI; x += 0.1) {
        double y = sin(x);
        int column = (x + M_PI) * (size - 1) / (2 * M_PI);
        int row = (1 - y) * (size - 1) / 2;

        if (row >= 0 && row < size && column >= 0 && column < size) {
            A[row][column] = '*';
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << A[i][j];
        }
        std::cout << std::endl;
    }
}