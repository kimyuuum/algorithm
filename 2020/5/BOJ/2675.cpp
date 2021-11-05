#include <cstring>
#include <iostream>
using namespace std;

int main() {
  int testcase;
  cin >> testcase;
  while (testcase--) {
    int num;
    string input;
    string res = "";
    cin >> num;
    cin >> input;
    for (int i = 0; i < input.size(); i++) {
      for (int j = 0; j < num; j++) {
        res += input[i];
      }
    }
    cout << res << "\n";
  }
  return 0;
}
