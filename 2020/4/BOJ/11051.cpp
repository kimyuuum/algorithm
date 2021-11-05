
#include <iostream>
using namespace std;
const int MAX = 1005;
long long arr[MAX][MAX];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  cin >> n >> k;

  arr[1][0] = 1;
  arr[1][1] = 1;
  arr[2][0] = 1;
  arr[2][1] = 2;
  arr[2][2] = 1;
  arr[3][0] = 1;
  arr[3][1] = 3;
  arr[3][2] = 3;
  arr[3][3] = 1;

  for (int i = 4; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      if (j == 0 || j == i) {
        arr[i][j] = 1;
      } else {
        arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j]) % 10007;
      }
    }
  }

  cout << arr[n][k];

  return 0;
}