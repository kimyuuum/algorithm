
#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, num;
  int cnt = 0;
  cin >> n;
  while (n--) {
    bool flag = false;
    cin >> num;
    if (num == 1) {
      flag = true;
    } else {
      for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
          flag = true;
          break;
        }
      }
    }
    if (!flag) {
      cnt++;
    }
  }

  cout << cnt;
  return 0;
}