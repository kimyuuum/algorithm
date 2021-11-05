
#include <iostream>
using namespace std;
const int MAX = 11;
int arr[MAX][MAX];
bool visited[MAX];
int n;
int res = 987654321;

void dfs(int start, int idx, int cnt, int val) {
  if (cnt == n && start == idx) {
    if (res > val) {
      res = val;
    }
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (arr[idx][i] == 0) {
      continue;
    }
    if (!visited[idx] && arr[idx][i] > 0) {
      visited[idx] = true;
      val += arr[idx][i];
      if (val <= res) {
        dfs(start, i, cnt + 1, val);
      }
      visited[idx] = false;
      val -= arr[idx][i];
    }
  }
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> arr[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    dfs(i, i, 0, 0);
  }
  cout << res;
  return 0;
}
