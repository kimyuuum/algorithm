
#include <iostream>
using namespace std;

int main() {
  string input;
  cin >> input;
  if (input.size() == 1) {
    input = '0' + input;
  }
  int cnt = 0;
  string res = input;

  while (1) {
    string ans = "";
    int temp = res[0] - '0' + res[1] - '0';
    string t = to_string(temp);
    if (t.size() == 1) {
      t = '0' + t;
    }
    ans += res[1];
    ans += t[1];
    cnt++;
    if (ans == input) {
      break;
    } else {
      res = ans;
    }
  }
  cout << cnt;
  return 0;
}