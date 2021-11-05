
#include <iostream>
using namespace std;
const int MAX = 1000001;
bool arr[MAX];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int m, n;
  cin >> m >> n;
  arr[1] = true;

  for (int i = 2; i * i <= n; i++) {
    if (!arr[i]) {
      for (int j = i * i; j <= n; j += i) {
        arr[j] = true;
      }
    }
  }

  for (int i = m; i <= n; i++) {
    if (!arr[i]) {
      cout << i << "\n";
    }
  }
  return 0;
}