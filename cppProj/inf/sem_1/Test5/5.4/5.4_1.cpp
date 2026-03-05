#include <iostream>
#include <cmath>

double calculate(int n) {
    double sum = 0.0;
    double den = 0.0;

    for (int i = 1; i <= n; ++i) {
        den += sin(i);
        if (den != 0.0) {
            sum += sin(i) / den;
        }
    }

    return sum;
}

int main() {
    int n;
    std::cin >> n;

    if (n <= 0) {
        std::cout << "0" << std::endl;
        return 0;
    }

    double result = calculate(n);
    std::cout << result << std::endl;

    return 0;
}