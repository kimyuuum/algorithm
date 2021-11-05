
#include <cstring>
#include <iostream>
using namespace std;
int arr[26];
int main() {
  string input;
  getline(cin, input);

  for (int i = 0; i < input.size(); i++) {
    if (input[i] >= 'a' && input[i] <= 'z') {
      arr[input[i] - 97]++;
    } else if (input[i] >= 'A' && input[i] <= 'Z') {
      arr[input[i] - 65]++;
    }
  }
  int cnt = 0;
  int num = 0;
  bool flag = true;
  for (int i = 0; i < 26; i++) {
    if (arr[i] % 2 != 0) {
      cnt++;
    }
  }

  if (cnt == 1 || cnt == 0) {
    cout << "true";
  } else {
    cout << "false";
  }
  return 0;
}