#include <iostream>
#include <cmath>

int main() {

  int a, x;
  std::cin >> x >> a;
  if (x == 0){
    std::cout << "Нет решений" << std::endl;
  }
  else{
    if (fabs(x) < 1) std::cout << a * log(fabs(x)) << std::endl;
    if (fabs(x) >= 1){
      if(a < x*x) std::cout << "Значение под корнем меньше нуля" << std::endl;
      else std:: cout << sqrt(a - (x*x)) << std::endl;
    } 
  }
  return 0;
}
