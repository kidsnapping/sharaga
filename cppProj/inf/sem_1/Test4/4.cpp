#include <iostream>

void generatePsevdoNumbers(int m, int i, int c, int s0, int count) {
    int s = s0;
    for (int n = 0; n < count; n++) {
        s = (m * s + i) % c;
        std::cout << s << " ";
    }
    std::cout << std::endl;
}

int main() {
    int m1 = 37, i1 = 3, c1 = 64;
    int m2 = 25173, i2 = 13849, c2 = 65537;
    int s0 = 0, count;
    std::cin >> count;
    generatePsevdoNumbers(m1, i1, c1, s0, count);
    generatePsevdoNumbers(m2, i2, c2, s0, count);
    return 0;
}
