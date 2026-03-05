#include <iostream>
#include <cmath>

int main() {
    int n;
    std::cin >> n;
    if (n > 0 ) for(int i = n; i < n + 10; i++) std::cout << i << std::endl;
    else std::cout << "Число не натуральное" << std::endl;
    return 0;
}