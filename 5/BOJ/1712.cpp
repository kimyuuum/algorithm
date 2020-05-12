#include <iostream>
using namespace std;
long long total, cost;
int main() {
  long long a, b, c;
  long long n = 0;
  cin >> a >> b >> c;
  if (c - b <= 0) {
    n = -1;
  } else {
    n = a / (c - b) + 1;
  }
  cout << n;
  return 0;
}