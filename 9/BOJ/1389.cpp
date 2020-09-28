
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 101;
const int INF = 987654321;
int d[MAX][MAX];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      d[i][j] = INF;
    }
  }

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    d[a][b] = 1;
    d[b][a] = 1;
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (d[i][j] > d[i][k] + d[k][j]) {
          d[i][j] = d[i][k] + d[k][j];
        }
      }
    }
  }

  pair<int, int> res = {INF, INF};

  for (int i = 1; i <= n; i++) {
    int sum = 0;
    for (int j = 1; j <= n; j++) {
      sum += d[i][j];
    }
    if (sum < res.second) {
      res = {i, sum};
    }
  }

  cout << res.first;

  return 0;
}