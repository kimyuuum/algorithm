
#include <iostream>
using namespace std;
const int MAX = 1005;
int arr[MAX];
int d[MAX];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  d[0] = 1;
  for (int i = 1; i < n; i++) {
    d[i] = 1;
    for (int j = 0; j < i; j++) {
      if (arr[j] < arr[i]) {
        d[i] = max(d[i], d[j] + 1);
      }
    }
  }
  int res = d[0];
  for (int i = 0; i < n; i++) {
    if (res < d[i]) {
      res = d[i];
    }
  }

  cout << res;

  return 0;
}
