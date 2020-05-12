#include <cstring>
#include <iostream>
using namespace std;
int al[26];

int main() {
  string input;
  cin >> input;

  for (int i = 0; i < input.size(); i++) {
    if (input[i] >= 'a' && input[i] <= 'z') {
      int idx = input[i] - 97;
      al[idx]++;
    } else if (input[i] >= 'A' && input[i] <= 'Z') {
      int idx = input[i] - 65;
      al[idx]++;
    }
  }

  int idx = 0;
  bool flag = false;
  for (int i = 1; i < 26; i++) {
    if (al[i] > al[idx]) {
      idx = i;
      flag = false;
    } else if (al[i] == al[idx] && al[i] != 0) {
      flag = true;
    }
  }

  if (flag) {
    cout << "?";
  } else {
    char c = idx + 65;
    cout << c;
  }
  return 0;
}