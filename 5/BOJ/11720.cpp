#include <cstring>
#include <iostream>

using namespace std;

int main() {
  int num;
  char input;
  int res = 0;
  cin >> num;
  for (int i = 0; i < num; i++) {
    cin >> input;
    res += input - 48;
  }
  cout << res;
  return 0;
}