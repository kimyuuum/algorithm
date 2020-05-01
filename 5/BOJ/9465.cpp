
#include <cstring>
#include <iostream>
using namespace std;
const int MAX = 100001;
int d[MAX][2];
int p[MAX][2];
int n;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int testcase;
  cin >> testcase;
  while (testcase--) {
    memset(p, 0, sizeof(p));
    memset(d, 0, sizeof(d));
    cin >> n;
    for (int j = 0; j < 2; j++) {
      for (int i = 1; i <= n; i++) {
        cin >> p[i][j];
      }
    }

    d[1][0] = p[1][0];
    d[1][1] = p[1][1];
    int res = 0;

    for (int i = 2; i <= n; i++) {
      d[i][0] = max(d[i - 2][1], d[i - 1][1]) + p[i][0];
      d[i][1] = max(d[i - 2][0], d[i - 1][0]) + p[i][1];

      res = max(res, max(d[i][0], d[i][1]));
    }

    cout << res << "\n";
  }
  return 0;
}