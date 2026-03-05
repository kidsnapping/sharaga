#include <iostream>
#include <fstream>
#include <string>

int main(){
    std::ifstream f("5.3_15.txt");
    std::string word;
    std::cin >> word;
    std::string w;
    while(f >> w){
        if(w == word){
            std::cout << "Found" << std::endl;
            return 0;
        }
    }
    std::cout << "Not found" << std::endl;
    return 0;
}
