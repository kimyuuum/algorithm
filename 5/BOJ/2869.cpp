
#include <iostream>
using namespace std;
int a, b, v;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> a >> b >> v;

  int right = v / (a - b) + 1;
  int left = 0;
  int res = 1000000001;

  while (left <= right) {
    int day = (left + right) / 2;
    if (day * (a - b) + a >= v) {
      if (res > day + 1) {
        res = day + 1;
      }
      right = day - 1;
    } else {
      left = day + 1;
    }
  }

  cout << res;
  return 0;
}

