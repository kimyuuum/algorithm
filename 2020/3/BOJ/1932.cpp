
#include <algorithm>
#include <iostream>
using namespace std;
long arr[501][501];
long d[501][501];
int n;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      cin >> arr[i][j];
    }
  }

  d[1][1] = arr[1][1];
  d[2][1] = d[1][1] + arr[2][1];
  d[2][2] = d[1][1] + arr[2][2];

  for (int i = 3; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      if (j == 1) {
        d[i][j] = d[i - 1][j] + arr[i][j];
      } else if (j == i) {
        d[i][j] = d[i - 1][j - 1] + arr[i][j];
      } else {
        d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + arr[i][j];
      }
    }
  }

  long max = 0;
  for (int i = 1; i <= n; i++) {
    if (max < d[n][i]) {
      max = d[n][i];
    }
  }

  cout << max;
  return 0;
}
