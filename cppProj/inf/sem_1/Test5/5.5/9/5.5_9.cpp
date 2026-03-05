#include <fstream>
#include <vector>
#include <algorithm>

int main()
{
    std::ifstream file_A("A.txt");
    std::ifstream file_B("B.txt");
    std::ofstream file_C("C.txt");
    std::vector<int> arr;
    int value;

    while (file_A >> value)
        arr.push_back(value);

    while (file_B >> value)
        arr.push_back(value);

    std::sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size(); ++i)
        file_C << arr[i] << " ";

    return 0;
}
