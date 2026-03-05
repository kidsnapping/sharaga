#include <iostream>
#include <cmath>

int main() {
    double x,y,b;
    std::cin >> x >> y >> b;
    if(b - y <= 0 or b - x < 0) std::cout << "Выход за область определения" << std::endl;
    else std::cout << log(b-y) * sqrt(b-x) << std::endl;
    return 0;
}