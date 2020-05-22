#include <iostream>
using namespace std;
long long x, y, z, res = 1000000000;

int main() {
  cin >> x >> y;
  z = (long long)(y * 100) / x;

  if (z >= 99) {
    cout << -1;
  } else {
    long long right = x;
    long long left = 1;

    while (left <= right) {
      long long mid = (long long)(left + right) / 2;
      long long percent = (long long)((y + mid) * 100) / (x + mid);

      if (percent > z) {
        if (res > mid) {
          res = mid;
        }
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }

    cout << res;
  }
  return 0;
}
