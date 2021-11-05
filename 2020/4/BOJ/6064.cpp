
#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int x, y, m, n;
  int testcase;
  cin >> testcase;
  while (testcase--) {
    cin >> m >> n >> x >> y;
    if (x == m) x = 0;
    if (y == n) y = 0;
    bool flag = false;
    for (int i = x; i <= m * n; i += m) {
      if (i % n == y) {
        cout << i << "\n";
        flag = true;
        break;
      }
    }

    if (!flag) {
      cout << "-1\n";
    }
  }

  return 0;
}