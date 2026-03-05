#include <iostream>

int main() {
    bool lamp, time, curtains;
    lamp = false;
    time = false;
    curtains = false;
    if((time == true and curtains == true) or lamp == true) std::cout << "В комнате светло" << std::endl;
    else std::cout << "В комнате темно" << std::endl;
    return 0;
}