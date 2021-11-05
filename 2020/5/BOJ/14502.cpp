#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int MAX = 9;
int n, m, res;
int map[MAX][MAX];
int test[MAX][MAX];
int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {-1, 0, 1, 0};

void spread() {
  queue<pair<int, int>> q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      test[i][j] = map[i][j];
      if (map[i][j] == 2) {
        q.push(make_pair(i, j));
      }
    }
  }

  while (!q.empty()) {
    int curX = q.front().first;
    int curY = q.front().second;

    q.pop();

    for (int i = 0; i < 4; i++) {
      int nextX = curX + dirX[i];
      int nextY = curY + dirY[i];

      if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m) {
        continue;
      }
      if (test[nextX][nextY] != 0) {
        continue;
      }
      q.push(make_pair(nextX, nextY));
      test[nextX][nextY] = 2;
    }
  }

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (test[i][j] == 0) {
        cnt++;
      }
    }
  }

  if (cnt > res) {
    res = cnt;
  }
}

void dfs(int x, int y, int count) {
  if (count == 3) {
    spread();
    return;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (map[i][j] == 0) {
        map[i][j] = 1;
        dfs(i, j, count + 1);
        map[i][j] = 0;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> map[i][j];
      test[i][j] = map[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (map[i][j] == 0) {
        map[i][j] = 1;
        dfs(i, j, 1);
        map[i][j] = 0;
      }
    }
  }

  cout << res;
  return 0;
}