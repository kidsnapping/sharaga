#include <iostream>
#include <cmath>

int main() {
    int y;
    for(double x = -4; x < 4; x+=0.5){
        if(x == 1) std::cout << "X: "<< x << "      Y: не имеет решений" << std::endl;
        else{
            y = (pow(x,2) - 2 *x + 2) / (x -1);
            std::cout << "X: "<< x << "     Y: " << y << std::endl;
        }
    }
    return 0;
}