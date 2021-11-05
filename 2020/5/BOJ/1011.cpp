#include <cmath>
#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int testcase;
  cin >> testcase;
  while (testcase--) {
    int x, y;
    cin >> x >> y;
    long long res = 0;
    long long dist = (long long)y - x;
    long long n = 0;
    while (1) {
      if (powl(n, 2) >= dist) {
        break;
      } else {
        n++;
      }
    }

    if (dist == powl(n, 2)) {
      res = (long long)2 * n - 1;
    } else {
      long long mid = (powl(n, 2) + powl(n - 1, 2)) / 2 + 1;
      if (dist >= mid) {
        res = (long long)2 * n - 1;
      } else {
        res = (long long)2 * n - 2;
      }
    }
    cout << res << "\n";
  }
  return 0;
}