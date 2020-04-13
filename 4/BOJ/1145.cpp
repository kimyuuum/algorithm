
#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a, b, c, d, e;
  int res = 1;
  cin >> a >> b >> c >> d >> e;

  while (1) {
    int cnt = 0;
    if (res % a == 0) {
      cnt++;
    }
    if (res % b == 0) {
      cnt++;
    }
    if (res % c == 0) {
      cnt++;
    }
    if (res % d == 0) {
      cnt++;
    }
    if (res % e == 0) {
      cnt++;
    }

    if (cnt >= 3) {
      cout << res;
      break;
    }

    res++;
  }

  return 0;
}