#include <iostream>
#include <string>

int F(char c){
    if(c=='I') return 1;
    if(c=='V') return 5;
    if(c=='X') return 10;
    if(c=='L') return 50;
    if(c=='C') return 100;
    if(c=='D') return 500;
    if(c=='M') return 1000;
    return 0;
}

int main(){
    std::string s;
    std::cin >> s;
    int r = 0;
    for(int i = 0; i < (int)s.size(); i++){
        int a = F(s[i]);
        int b = 0;
        if(i+1 < (int)s.size()) b = F(s[i+1]);
        if(a < b) r -= a;
        else r += a;
    }
    std::cout << r << std::endl;
}
