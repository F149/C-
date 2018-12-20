///////////////////////////////////////////////////////////////////////////////
// Напишите функцию, которая
//  - называется IsPalindrom
//  - возвращает bool
//  - принимает параметр типа string и возвращает, является ли переданная
//    строка палиндромом
//
// Палиндром - это слово или фраза, которые одинаково читаются слева направо
// и справа налево. Пустая строка является палиндромом.
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;

bool IsPalindrom(string s) {
    string r = "";
    for (int i = s.size() - 1; i >= 0; --i) {
        r += s[i];
    }
    if (s == r) {
        return true;
    } else {
        return false;
    }
}

int main() {
    string s2;
    cin >> s2;
    cout << IsPalindrom(s2);
    return 0;
}

///////////////////// - SOLUTION - /////////////////////
//
//bool IsPalindrom(string s) {
//    for (size_t i = 0; i < s.size() / 2; ++i) {
//        if (s[i] != s[s.size() - i - 1]) {
//            return false;
//        }
//    }
//    return true;
//}
