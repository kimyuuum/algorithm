
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int main() {
  string a, b;
  cin >> a >> b;

  int num1, num2;
  string temp1, temp2;
  for (int i = 2; i >= 0; i--) {
    temp1 += a[i];
    temp2 += b[i];
  }

  num1 = atoi(temp1.c_str());
  num2 = atoi(temp2.c_str());
  cout << max(num1, num2);
  return 0;
}