#include <iostream>

double rectangle(double width, double height) {
    return width * height;
}

double triangle(double base, double height) {
    return 0.5 * base * height;
}

double circle(double radius) {
    return 3.14 * radius * radius;
}


int main()
{
    setlocale(0, "");
    int choice;
    double width, height, base, radius;

    do {
        std::cout << "Выберите фигуру:\n" << "1. Прямоугольник\n" << "2. Треугольник\n" << "3. Круг\n" << "0. Выход\n";
        std::cin >> choice;

        switch (choice) {

        case 1:
            std::cout << "Введите ширину прямоугольника: ";
            std::cin >> width;
            std::cout << "Введите высоту прямоугольника: ";
            std::cin >> height;
            std::cout << "Площадь прямоугольника: " << rectangle(width, height) << std::endl;
            break;
        case 2:
            std::cout << "Введите основание треугольника: ";
            std::cin >> base;
            std::cout << "Введите высоту треугольника: ";
            std::cin >> height;
            std::cout << "Площадь треугольника: " << triangle(base, height) << std::endl;
            break;
        case 3:
            std::cout << "Введите радиус круга: ";
            std::cin >> radius;
            std::cout << "Площадь круга: " << circle(radius) << std::endl;
            break;
        case 0:
            break;
        default:
            std::cout << "Неправильное число!\n";
        }
    } while (choice != 0);

    return 0;
}
