#include <iostream>
#include <cmath>

int main() {
    double S, p, n;
    std::cin >> S >> p >> n;
    double r = p / 100.0;
    double m = (S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));

    std::cout << m << std::endl;
    return 0;
}
