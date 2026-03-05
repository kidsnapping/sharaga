#include <iostream>
#include <fstream>

int main() {
    std::ifstream f("2.txt");
    char c;
    while (f.get(c)){
         if (isdigit(c)) std::cout << c;
    }
       std::cout << std::endl;
}