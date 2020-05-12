#include <cstring>
#include <iostream>
using namespace std;
int a[26];

int main() {
  memset(a, -1, sizeof(a));
  string input;
  cin >> input;

  for (int i = 0; i < input.size(); i++) {
    char al = input[i];
    int idx = al - 97;
    if (a[idx] == -1) {
      a[idx] = i;
    }
  }

  for (int i = 0; i < 26; i++) {
    cout << a[i] << " ";
  }

  return 0;
}