///////////////////////////////////////////////////////////////////////////////
// Напишите функцию, которая
//  - называется PalindromFilter
//  - возвращает vector<string>
//  - принимает vector<string> words и int minLength и возвращает
//  - все строки из вектора words, которые являются палиндромами и имеют длину
//    не меньше minLength
// Входной вектор содержит не более 100 строк, длина каждой строки не
// больше 100 символов.
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> PalindromFilter(vector<string> words, int minLength){
    vector<string> palindrom;
    for (auto w : words) {
        string r = "";
        for (int i = w.size() - 1; i >= 0; --i) {
            r += w[i];
        }
        if (w == r and w.size() >= minLength){
            palindrom.push_back(w);
        }
    }
    return palindrom;
}

int main() {
    vector<string> v;
    int n;
    cin >> n;
    vector<string> total;

    total = PalindromFilter(v, n);
    for (auto t : total) {
        cout << t << " ";
    }
    return 0;
}
