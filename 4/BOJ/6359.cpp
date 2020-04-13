
#include <cstring>
#include <iostream>
using namespace std;
const int MAX = 100;
bool arr[MAX];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, testcase;
  cin >> testcase;
  while (testcase--) {
    cin >> n;
    int cnt = 0;
    memset(arr, false, sizeof(arr));
    for (int i = 2; i <= n; i++) {
      for (int j = i; j <= n; j += i) {
        if (!arr[j]) {
          arr[j] = true;
        } else {
          arr[j] = false;
        }
      }
    }

    for (int i = 1; i <= n; i++) {
      if (!arr[i]) {
        cnt++;
      }
    }
    cout << cnt << "\n";
  }
  return 0;
}