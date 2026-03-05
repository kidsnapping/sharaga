#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main()
{
    int N;
    std::cin >> N;

    std::vector<int> a(N);
    std::ofstream file_1("A.txt");

    for (int i = 0; i < N; i++){
        std::cin >> a[i];
        file_1 << a[i] << " ";
    }
    file_1.close();

    std::sort(a.begin(), a.end());

    int maxCount = 1;
    int count = 1;

    for (int i = 1; i < N; i++){
        if (a[i] == a[i - 1])
            count++;
        else
        {
            if (count > maxCount)
                maxCount = count;
            count = 1;
        }
    }
    if (count > maxCount)
        maxCount = count;

    std::vector<int> res;
    count = 1;

    for (int i = 1; i < N; i++){
        if (a[i] == a[i - 1])
            count++;
        else{
            if (count == maxCount)
                res.push_back(a[i - 1]);
            count = 1;
        }
    }
    if (count == maxCount)
        res.push_back(a[N - 1]);

    std::ofstream file_2("B.txt");
    for (int i = 0; i < (int)res.size(); i++)
        file_2 << res[i] << " ";
    file_2.close();

    std::ifstream file_A("A.txt");
    int x;
    std::cout << "A.txt: ";
    while (file_A >> x)
        std::cout << x << " ";
    std::cout << std::endl;
    file_A.close();

    std::ifstream file_B("B.txt");
    std::cout << "B.txt: ";
    while (file_B >> x)
        std::cout << x << " ";
    std::cout << std::endl;
    file_B.close();

    return 0;
}
