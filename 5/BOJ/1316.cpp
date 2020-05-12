#include <cstring>
#include <iostream>
using namespace std;
int al[26];

int main() {
  int testcase;
  cin >> testcase;
  int res = 0;
  while (testcase--) {
    memset(al, -1, sizeof(al));
    bool flag = false;
    string input;
    cin >> input;
    for (int i = 0; i < input.size(); i++) {
      int a = input[i] - 97;
      if (al[a] == -1) {
        al[a] = i;
      } else {
        if (i - al[a] > 1) {
          flag = true;
          break;
        } else {
          al[a] = i;
        }
      }
    }
    if (!flag) {
      res++;
    }
  }
  cout << res;
}