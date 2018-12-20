#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    string a, b, c;
    cin >> a >> b >> c;

    vector<string> words = {a, b, c};
    sort(begin(words), end(words));
    cout << words[0];

    return 0;
}
