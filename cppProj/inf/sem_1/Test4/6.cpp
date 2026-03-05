#include <iostream>
#include <iomanip>

int main() {
    const int sellers = 3;
    const int goods = 4;
    const int columnsB = 2;

    double A[sellers][goods] = {
        {5, 2, 0, 10},
        {3, 5, 2, 5},
        {20, 0, 0, 0}
    };

    double B[goods][columnsB] = {
        {1.20, 0.50},
        {2.80, 0.40},
        {5.00, 1.00},
        {2.00, 1.50}
    };

    double C[sellers][columnsB] = {0};

    for (int i = 0; i < sellers; i++) {
        for (int j = 0; j < columnsB; j++) {
            for (int k = 0; k < goods; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    std::cout << "Матрица C (результат A×B):" << std::endl;
    for (int i = 0; i < sellers; i++) {
        for (int j = 0; j < columnsB; j++) {
            std::cout << C[i][j] << " ";
        }
        std::cout << std::endl;
    }

    int maxSalesIndex = 0, minSalesIndex = 0;
    for (int i = 1; i < sellers; i++) {
        if (C[i][0] > C[maxSalesIndex][0]) maxSalesIndex = i;
        if (C[i][0] < C[minSalesIndex][0]) minSalesIndex = i;
    }

    int maxCommIndex = 0, minCommIndex = 0;
    for (int i = 1; i < sellers; i++) {
        if (C[i][1] > C[maxCommIndex][1]) maxCommIndex = i;
        if (C[i][1] < C[minCommIndex][1]) minCommIndex = i;
    }

    double totalSales = 0;
    for (int i = 0; i < sellers; i++) totalSales += C[i][0];

    double totalComm = 0;
    for (int i = 0; i < sellers; i++) totalComm += C[i][1];

    double totalThroughHands = totalSales + totalComm;
    std::cout << std::endl;
    std::cout << "1) Больше всего выручил продавец " << maxSalesIndex + 1 << ", меньше всего " << minSalesIndex + 1 << std::endl;
    std::cout << "2) Больше всего комиссионных получил продавец " << maxCommIndex + 1 << ", меньше всего " << minCommIndex + 1 << std::endl;
    std::cout << "3) Общая сумма денег за проданные товары: " << totalSales << std::endl;
    std::cout << "4) Общая сумма комиссионных: " << totalComm << std::endl;
    std::cout << "5) Общая сумма денег, прошедших через руки продавцов: " << totalThroughHands << std::endl;

    return 0;
}
