#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

int main()
{
    std::ifstream file_in("words.txt");
   
    std::vector<std::string> words;
    std::string word;
    std::string input;

    while (file_in >> word)
        words.push_back(word);

    std::sort(words.begin(), words.end());
    for (int j = 0; j < (int)words.size(); j++)
        std::cout << words[j] << " ";

    std::cin >> input;    
    words.push_back(input);
    std::sort(words.begin(), words.end());

    std::ofstream file_out("words.txt");
    for (int i = 0; i < (int)words.size(); i++){
        file_out << words[i] << " ";
        std::cout << words[i] << " ";
    }

    return 0;
}
