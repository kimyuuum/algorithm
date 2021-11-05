
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int MAX = 55;
int map[MAX][MAX];
bool visited[MAX][MAX];
int n, m, k, res;
int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {-1, 0, 1, 0};

void bfs(int x, int y) {
  queue<pair<int, int>> q;
  q.push(make_pair(x, y));
  visited[x][y] = true;

  while (!q.empty()) {
    int curX = q.front().first;
    int curY = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int nextX = curX + dirX[i];
      int nextY = curY + dirY[i];

      if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n) {
        continue;
      }
      if (visited[nextX][nextY] || map[nextX][nextY] == 0) {
        continue;
      }

      q.push(make_pair(nextX, nextY));
      visited[nextX][nextY] = true;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int testcase;
  cin >> testcase;
  while (testcase--) {
    res = 0;
    memset(visited, false, sizeof(visited));
    memset(map, 0, sizeof(map));
    cin >> m >> n >> k;
    while (k--) {
      int x, y;
      cin >> x >> y;
      map[x][y] = 1;
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (map[j][i] == 1 && !visited[j][i]) {
          bfs(j, i);
          res++;
        }
      }
    }
    cout << res << "\n";
  }

  return 0;
}