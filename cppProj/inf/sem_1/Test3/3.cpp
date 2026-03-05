#include <iostream>
#include <string>
#include <algorithm> 

void selectionSort(std::string& str) {
    int n = str.length();
        for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (str[j] < str[minIndex]) {
                minIndex = j;
            }
        }
                if (minIndex != i) {
            std::swap(str[i], str[minIndex]);
        }
    }
}

int main() {
    std::string line = "qjklvbqmvaqv1245malwerk89aopqz";
    
    selectionSort(line);
    std::cout << "Длина строки: " << line.length() << std::endl << "Отсортированная строка: " << line << std::endl;
    return 0;
}