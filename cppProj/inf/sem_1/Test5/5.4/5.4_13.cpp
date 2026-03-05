#include <iostream>

int main() {
    for (int m = 1; m < 27; m++) {
        std::cout << "Для m = " << m << ": ";
        for (int num = 100; num <= 999; num++) {
            int sum = (num / 100) + ((num / 10) % 10) + (num % 10);
            if (sum == m) {
                std::cout << num << " ";
            }
        }
        std::cout << "\n";
    }
    return 0;
}