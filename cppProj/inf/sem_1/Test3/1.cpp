#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file("1.txt"); 
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    return 0;
}
