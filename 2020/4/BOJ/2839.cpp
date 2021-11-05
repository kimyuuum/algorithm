
#include <iostream>
using namespace std;
int n;
int mix;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  bool flag = true;
  int cnt = 0;
  while (1) {
    if (n % 5 == 0) {
      cnt += n / 5;
      break;
    }
    cnt++;
    n -= 3;

    if (n < 0) {
      cout << "-1";
      flag = false;
      break;
    }
  }

  if (flag) {
    cout << cnt;
  }
  return 0;
}