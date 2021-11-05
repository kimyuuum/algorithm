#include <iostream>
#include <queue>
using namespace std;
const int MAX = 501;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {-1, 0, 1, 0};
int n, m, cnt, pic;

void bfs(int x, int y) {
  int s = 1;
  cnt++;
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
      if (visited[nextX][nextY] || !map[nextX][nextY]) {
        continue;
      }

      visited[nextX][nextY] = true;
      q.push(make_pair(nextX, nextY));
      s++;
    }
  }

  if (pic < s) {
    pic = s;
  }
}
int main() {
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> map[j][i];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (map[j][i] == 1 && !visited[j][i]) {
        bfs(j, i);
      }
    }
  }

  cout << cnt << "\n" << pic;
  return 0;
}