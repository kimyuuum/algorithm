
#include <iostream>
using namespace std;
long d[91];

int main() {
  long n;
  cin >> n;
  d[1] = 1;
  d[2] = 1;

  for (long i = 3; i <= n; i++) {
    d[i] = d[i - 2] + d[i - 1];
  }

  cout << d[n];

  return 0;
}