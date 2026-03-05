#include <fstream>
#include <iostream>

int main() {
    std::ofstream out("6.txt");
    double num;
    for (int i = 0; i < 10; i++) {
        std::cin >> num;
        out << num << " ";
    }
    out.close();

    std::ifstream in("6.txt");
    double sum = 0;
    while (in >> num) {
        sum += num;
    }
    in.close();

    std::cout << sum << std::endl;
    return 0;
}