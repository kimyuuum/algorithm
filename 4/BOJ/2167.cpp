#include <iostream>
using namespace std;
const int MAX = 301;
int arr[MAX][MAX];
int dp[MAX][MAX];
int n, m, k;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> arr[i][j];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
    }
  }

  cin >> k;
  while (k--) {
    int res = 0;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    res = dp[c][d] - dp[c][b - 1] - dp[a - 1][d] + dp[a - 1][b - 1];
    cout << res << "\n";
  }

  return 0;
}