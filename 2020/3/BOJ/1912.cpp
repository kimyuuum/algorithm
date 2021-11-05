
#include <iostream>
using namespace std;
const int MAX = 100005;
int arr[MAX];
int d[MAX];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  d[0] = arr[0];
  int res = d[0];

  for (int i = 1; i < n; i++) {
    d[i] = max(d[i - 1], 0) + arr[i];

    if (res <= d[i]) {
      res = d[i];
    }
  }

  cout << res;

  return 0;
}
