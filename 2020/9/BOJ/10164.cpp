
#include <iostream>
using namespace std;
const int MAX = 18;
int m, n, k;
int dp[MAX][MAX] = {
    0,
};
int num[MAX][MAX] = {
    0,
};

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> n >> m >> k;
  int tarX, tarY, cnt = 1;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      num[i][j] = cnt;
      if (cnt == k) {
        tarX = i;
        tarY = j;
      }
      cnt++;
    }
  }

  for (int i = 0; i < n; i++) {
    dp[i][0] = 1;
  }

  for (int i = 0; i < m; i++) {
    dp[0][i] = 1;
  }

  if (k != 0) {
    for (int i = 1; i <= tarX; i++) {
      for (int j = 1; j <= tarY; j++) {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }

    for (int i = tarY; i < m; i++) {
      dp[tarX][i] = dp[tarX][tarY];
    }
    for (int j = tarX; j < n; j++) {
      dp[j][tarY] = dp[tarX][tarY];
    }

    for (int i = tarX + 1; i < n; i++) {
      for (int j = tarY + 1; j < m; j++) {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }
  } else {
    for (int i = 1; i < n; i++) {
      for (int j = 1; j < m; j++) {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }
  }
  cout << dp[n - 1][m - 1];

  return 0;
}
