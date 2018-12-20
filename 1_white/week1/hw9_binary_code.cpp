///////////////////////////////////////////////////////////////////////////////
//На вход дано целое положительное число N. Выведите его в двоичной
//системе счисления без ведущих нулей.
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a, b = 0;
    cin >> a;
    vector<int> bin_count;

    while (a > 0) {
        b = a - (a / 2) * 2;
        if (b == 1) {
            bin_count.push_back(1);
        } else if (b == 0 && a != 0) {
            bin_count.push_back(0);
        }
        a = a / 2;
    }

    for (int i = bin_count.size() - 1; i >= 0; --i) {
        cout << bin_count[i];
    }

    return 0;
}
