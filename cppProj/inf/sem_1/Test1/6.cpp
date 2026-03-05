#include <iostream>
#include <math.h>
int main() {
    int h,R, r, l;
    double p = 3.14;
    std::cout << "Введите данные в порядке 'Высота, малый радиус, больший радиус :" << std::endl;
    std::cin >> h >> R >> r;
    if(h < 0 or R < 0 or r < 0) std::cout << "Ошибка: отрицательные стороны" << std::endl;
    else {
        l = sqrt(pow(r-R,2) + pow(h,2));
        double V = ((p*h)/3) * (pow(R,2) + R*r + pow(r,2));
        double S = p * (pow(R,2) + ((R + r) * l) + pow(r,2));
        std::cout << "Ответ: " << "\n" << "V = " << V << " S = " << S << std::endl;
    }
    return 0;
}