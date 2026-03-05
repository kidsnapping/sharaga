#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    if (n < 2) {
        std::cout << "Нет простых чисел" << std::endl;
        return 0;
    }

    std::vector<bool> is_prime(n + 1, true);
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            for (int j = 2 * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }

    std::cout << "Простые числа от 2 до " << n << std::endl;
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
