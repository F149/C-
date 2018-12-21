///////////////////////////////////////////////////////////////////////////////
// Реализуйте функцию vector<int> Reversed(const vector<int>& v), возвращающую
// копию вектора v, в которой числа переставлены в обратном порядке.
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <vector>
using namespace std;


vector<int> Reversed(const vector<int>& v) {
    vector<int> tmp;
    for (int i = v.size() - 1; i >= 0; --i) {
        tmp.push_back(v[i]);
    }
    return tmp;
}

int main() {
  vector<int> numbers = {1, 5, 3, 4, 2};
  vector<int> num;
  num = Reversed(numbers);
  // num должен оказаться равен {2, 4, 3, 5, 1}
  for (auto n : num) {
    cout << n << " ";
  }
  return 0;
}


////////////////////////////////// -SOLUTION- /////////////////////////////////
//
//vector<int> Reversed(const vector<int>& input) {
//  auto seq = input;
//  for (int i = 0; i < seq.size() / 2; ++i) {
//    auto tmp = seq[i];
//    seq[i] = seq[seq.size() - 1 - i];
//    seq[seq.size() - 1 - i] = tmp;
//  }
//  return seq;
//}
//
///////////////////////////////////////////////////////////////////////////////
