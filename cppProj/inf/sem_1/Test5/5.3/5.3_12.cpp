#include <iostream>
#include <fstream>
#include <string>

int main(){
    std::ifstream f("5.3_12.txt");
    std::string line;
    while(std::getline(f, line)){
        std::cout << line << std::endl;
    }
    return 0;
}
