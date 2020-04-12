

#include <iostream>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  int res = 1;
  for (int i = 1; i <= n; i++) {
    res *= i;
  }

  for (int i = 1; i <= k; i++) {
    res /= i;
  }
  for (int i = 1; i <= (n - k); i++) {
    res /= i;
  }

  cout << res;

  return 0;
}