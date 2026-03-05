#include <iostream>
#include <string>

int val(char c){
    if(c >= '0' && c <= '9') return c - '0';
    if(c >= 'A' && c <= 'Z') return c - 'A' + 10;
    if(c >= 'a' && c <= 'z') return c - 'a' + 10;
    return 0;
}

char digit(int x){
    if(x < 10) return '0' + x;
    return 'A' + (x - 10);
}

int main(){
    std::string s;
    int oldb, newb;
    std::cin >> s >> oldb >> newb;

    long long dec = 0; 
    for(int i = 0; i < (int)s.size(); i++){
        dec = dec * oldb + val(s[i]);
    }

    if(dec == 0){
        std::cout << 0 << std::endl;
        return 0;
    }

    std::string out = "";
    while(dec > 0){
        int r = dec % newb;
        out = digit(r) + out;
        dec /= newb;
    }

    std::cout << out << std::endl;
}
