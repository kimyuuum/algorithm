#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 2001;
vector<int> v[MAX];
bool visited[MAX] = {
    false,
};
int n, m;
bool isPossible = false;

void dfs(int curX, int cnt) {
  if (cnt == 5) {
    isPossible = true;
    return;
  }

  for (int i = 0; i < v[curX].size(); i++) {
    int nextIdx = v[curX][i];
    if (visited[nextIdx]) {
      continue;
    }
    visited[nextIdx] = true;
    dfs(nextIdx, cnt + 1);
    visited[nextIdx] = false;
  }

  return;
}

int main() {
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }

  for (int i = 0; i < n; i++) {
    sort(v[i].begin(), v[i].end());
  }

  for (int i = 0; i < n; i++) {
    visited[i] = true;
    for (int j = 0; j < v[i].size(); j++) {
      int nextIdx = v[i][j];
      visited[nextIdx] = true;
      dfs(nextIdx, 2);
      visited[nextIdx] = false;
    }
    if (isPossible) {
      break;
    }
    visited[i] = false;
  }

  cout << isPossible;
  return 0;
}