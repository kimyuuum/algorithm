
#include <iostream>
using namespace std;
const int MAX = 100;
const long num = 1000000000;
long d[MAX][MAX];

int main() {
  int n;
  cin >> n;
  long res = 0;

  for (int i = 1; i < 10; i++) {
    d[1][i] = 1;
  }

  for (int i = 2; i <= n; i++) {
    d[i][0] = d[i - 1][1];
    for (int j = 1; j < 10; j++) {
      if (j == 0) {
        d[i][j] = (d[i - 2][1] + d[i - 1][2]) % num;
      } else if (j == 9) {
        d[i][j] = (d[i - 1][8]) % num;
      } else {
        d[i][j] = (d[i - 1][j - 1] + d[i - 1][j + 1]) % num;
      }
    }
  }

  for (int i = 0; i < 10; i++) {
    res += d[n][i];
  }

  cout << res % num;

  return 0;
}