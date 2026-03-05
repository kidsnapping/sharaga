#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;
    int x = a, y = b;

    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    std::cout << "НОД (делением): " << a << std::endl;

    while (x != y) {
        if (x > y) x -= y;
        else y -= x;
    }
    std::cout << "НОД (вычитанием): " << x << std::endl;

    return 0;
}
