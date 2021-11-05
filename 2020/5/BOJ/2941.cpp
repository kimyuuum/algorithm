#include <cstring>
#include <iostream>
using namespace std;

int main() {
  string input;
  cin >> input;
  int pos = 0;
  for (int i = 0; i < input.size(); i++) {
    if (input[i] == 'j') {
      if (i >= 1) {
        if (input[i - 1] == 'l' || input[i - 1] == 'n') {
          continue;
        }
      }
    } else if (input[i] == '-') {
      continue;
    } else if (input[i] == '=') {
      if (i >= 2) {
        if (input[i - 1] == 'z' && input[i - 2] == 'd') {
          pos -= 2;
        } else {
          continue;
        }
      } else {
        continue;
      }
    }
    pos++;
  }
  cout << pos;
  return 0;
}