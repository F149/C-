///////////////////////////////////////////////////////////////////////////////
// Напишите функцию UpdateIfGreater, которая принимает два целочисленных
// аргумента: first и second. Если first оказался больше second, Ваша функция
// должна записывать в second значение параметра first. При этом изменение
// параметра second должно быть видно на вызывающей стороне.
//
// Пример:
//  int a = 4;
//  int b = 2;
//  UpdateIfGreater(a, b);
//  //b должно стать равно 4
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

void UpdateIfGreater(const int& first, int& second) {
    int tmp = first;
    if (first > second) {
        second = tmp;
    }
}

int main() {
    int a = 4;
    int b = 2;
    UpdateIfGreater(a, b);
    cout << b;
    return 0;
}
