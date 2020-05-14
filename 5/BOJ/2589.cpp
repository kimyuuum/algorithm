#include <iostream>
#include <queue>
using namespace std;
const int MAX = 51;
char map[MAX][MAX];
bool visited[MAX][MAX];
int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {-1, 0, 1, 0};
int n, m;

int bfs(int x, int y) {
  queue<pair<int, pair<int, int>>> q;
  q.push(make_pair(0, make_pair(x, y)));
  visited[x][y] = true;
  int r = 0;
  while (!q.empty()) {
    int size = q.size();
    for (int s = 0; s < size; s++) {
      int curX = q.front().second.first;
      int curY = q.front().second.second;
      int cnt = q.front().first;
      q.pop();
      r = cnt;

      for (int i = 0; i < 4; i++) {
        int nextX = curX + dirX[i];
        int nextY = curY + dirY[i];

        if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n) {
          continue;
        }
        if (visited[nextX][nextY] || map[nextX][nextY] != 'L') {
          continue;
        }
        q.push(make_pair(cnt + 1, make_pair(nextX, nextY)));
        visited[nextX][nextY] = true;
      }
    }
  }
  return r;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> map[j][i];
    }
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (map[j][i] == 'L') {
        memset(visited, false, sizeof(visited));
        int num = bfs(j, i);
        if (num > res) {
          res = num;
        }
      }
    }
  }

  cout << res;
  return 0;
}