#include <iostream>

int main()
{
    long long fact[11];
    fact[0] = 1;
    for(int i = 1; i <= 10; i++) fact[i] = fact[i - 1] * i;

    long long per[11];
    per[0] = 1;
    per[1] = 0;
    for(int i = 2; i <= 10; i++)
        per[i] = (i - 1) * (per[i - 1] + per[i - 2]);

    long long total = fact[10];
    long long match = total - per[10];

    std::cout << match << std::endl;
    return 0;
}
