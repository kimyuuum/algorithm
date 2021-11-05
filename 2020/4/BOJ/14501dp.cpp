
#include <algorithm>
#include <iostream>
using namespace std;
const int MAX = 16;
int dp[MAX];
int p[MAX];
int t[MAX];
int n;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int a, b;
    cin >> t[i] >> p[i];
  }

  for (int i = n; i >= 1; i--) {
    if (i + t[i] > n + 1) {
      dp[i] = dp[i + 1];
    } else {
      dp[i] = max(dp[i + 1], dp[i + t[i]] + p[i]);
    }
  }

  cout << dp[1];
  return 0;
}