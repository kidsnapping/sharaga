#include <iostream>
#include <cmath>

double pay(double S, double r, int n) {
    return (S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));
}

int main() {
    double S, m;
    int n;
    std::cin >> S >> n >> m;

    double left = 0.0, right = 1.0; 
    double r;
    for (int i = 0; i < 100; i++) {
        r = (left + right) / 2.0;
        double m_calc = pay(S, r, n);
        if (m_calc > m) 
            right = r;
        else 
            left = r;
    }

    double p = r * 100;
    std::cout << " p = " << p << std::endl;

    return 0;
}
