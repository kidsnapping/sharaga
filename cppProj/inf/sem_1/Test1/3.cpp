#include <iostream>

int main() {
    int b, c;
    std::cin >> b >> c;
    if(b == 0) std::cout << "x = не имееет решений" << std::endl;
    std::cout << "x = " << -c / b << "\n";
    return 0;
}