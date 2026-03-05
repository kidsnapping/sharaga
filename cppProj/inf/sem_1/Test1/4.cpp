#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;

    if (a == 0 && b == 0 && c == 0) {
        cout << "Бесконечно много решений" << endl;
    } else if (a == 0 && b == 0) {
        cout << "Нет решений" << endl;
    } else if (a == 0) {
        if(c == 0) cout << "Одно решение: x = 0" << endl;
        else cout << "Одно решение: x = " << -c / b << endl;
    } else {
        int D = b*b - 4*a*c;
        if (D < 0) {
            cout << "Нет решений" << endl;
        } else if (D == 0) {
            cout << "Одно решение: x = " << -b / (2*a) << endl;
        } else {
            int x1 = (-b + sqrt(D)) / (2*a);
            int x2 = (-b - sqrt(D)) / (2*a);
            cout << "x1 = " << x1 << ", x2 = " << x2 << endl;
        }
    }
    return 0;
}
