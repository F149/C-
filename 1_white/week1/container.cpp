#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  vector<int> num = {2, 22, 222, 2222, 22222, 5, 5, 5};
  int quantity = 0;
  for (auto x : num) {
    if (x == 5) {
      quantity +=1;
    }
  }
  cout << "There are " << quantity << " fives.\n";

  int quantity2 = count(begin(num), end(num), 22);
  cout << "There are " << quantity2 << " twenty two.\n";

  sort(begin(num), end(num));
  cout << "Sorted num is: " << num;

  for (auto n : num){
    cout << n << "_";
  }

  string s = "CCXXII";
  for (char c : s){
    cout << c << ",";
  }
}
