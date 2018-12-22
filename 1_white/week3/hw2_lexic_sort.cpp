///////////////////////////////////////////////////////////////////////////////
//
//  Задание по программированию: Сортировка без учёта регистра
//    Условие
//  В стандартном потоке дана одна строка, состоящая из числа N и следующих
//  за ним N строк S. Между собой число и строки разделены пробелом.
//
//  Отсортируйте строки S в лексикографическом порядке по возрастанию,
//  игнорируя регистр букв, и выведите их в стандартный поток вывода.
//
//  Ограничения
//    0 <= N <= 1000
//    1 <= |S| <= 15
//  Каждая строка S[i] может состоять из следующих символов: [0-9,a-z,A-Z]
//    Примеры
//    stdin	     stdout
//    2 q A	     A q
//    3 a C b	   a b C
//
//  Подсказка
//  Обратите внимание на функцию tolower.
//  http://www.cplusplus.com/reference/cctype/tolower/
//
///////////////////////////////////////////////////////////////////////////////
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void PrintVector(const vector<string>& v) {
    for (const auto i : v) {
        cout << i << " ";
    }
}

string Transform(string& s) {
    string temp = "";
    for (int i = 0; i < s.size(); ++i) {
        temp += tolower(s[i]);
    }
    return temp;
}

bool Compare(string i, string j) {
    return Transform(i) < Transform(j);
}

int main() {
    int n;
    cin >> n;
    vector<string> v(n);

    for (string& w : v) {
        cin >> w;
    }

    sort(begin(v), end(v), Compare);
    PrintVector(v);

    return 0;
}
