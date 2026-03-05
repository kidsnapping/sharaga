#include <iostream>

int main() {
    double a,b;
    std::cin>>a>>b;
    std::cout << "Суммa:" << a+b << std::endl;
    std::cout << "Разность:"<< a-b << std::endl;
    std::cout << "Произведение:" << a*b << std::endl;
    if(b == 0) std::cout << "Частное: Нет решений" << std::endl;
    else std::cout << "Частное:"<< a/b << std::endl;
    return 0;
}
