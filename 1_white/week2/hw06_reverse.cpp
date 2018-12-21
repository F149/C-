///////////////////////////////////////////////////////////////////////////////
//
// Разворот последовательности.
// Реализуйте функцию void Reverse(vector& v), которая переставляет элементы
// вектора в обратном порядке.
//
//  Пример:
//   vector<int> numbers = {1, 5, 3, 4, 2};
//   Reverse(numbers);
//   //numbers должен оказаться равен {2, 4, 3, 5, 1}
//
// Пояснение.
// В этой задаче на проверку вам надо прислать файл с реализацией функции
// Reverse.Этот файл не должен содержать функцию main. Если в нём будет
// функция main, вы получите ошибку компиляции.
//
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <vector>
using namespace std;


void Reverse(vector<int>& v) {
    vector<int> tmp;
    for (int i = v.size() - 1; i >= 0; --i) {
        tmp.push_back(v[i]);
    }
    v.clear();
    v = tmp;
}

//int main() {
//    vector<int> numbers = {1, 5, 3, 4, 2};
//    Reverse(numbers);
//    for (auto n : numbers) {
//        cout << n << " ";
//    }
//    return 0;
//}
