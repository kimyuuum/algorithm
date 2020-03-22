
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct vec {
  int x;
  int y;
};
const int MAX = 101;
bool light[MAX][MAX];
bool visited[MAX][MAX];
int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {-1, 0, 1, 0};
vector<vec> v[MAX][MAX];
queue<pair<int, int>> q;
int n, m;

void bfs() {
  while (1) {
    memset(visited, false, sizeof(visited));  // cstring헤터 필요 vis를 초기화
    queue<pair<int, int>> q;
    q.push(make_pair(1, 1));
    visited[1][1] = true;
    light[1][1] = true;
    bool flag = false;

    while (!q.empty()) {
      int curX = q.front().first;
      int curY = q.front().second;
      q.pop();
      if (!v[curX][curY].empty()) {
        for (int i = 0; i < v[curX][curY].size(); i++) {
          int nextX = v[curX][curY][i].x;
          int nextY = v[curX][curY][i].y;
          light[nextX][nextY] = true;
        }
        v[curX][curY].clear();
        flag = true;
      }
      for (int i = 0; i < 4; i++) {
        int nextX = curX + dirX[i];
        int nextY = curY + dirY[i];

        if (nextX < 1 || nextX > n || nextY < 1 || nextY > n) continue;
        if (!light[nextX][nextY] || visited[nextX][nextY]) continue;
        q.push(make_pair(nextX, nextY));
        visited[nextX][nextY] = true;
      }
    }
    if (!flag) break;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int a, b, x, y;

  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    cin >> x >> y >> a >> b;
    v[x][y].push_back({a, b});
  }

  bfs();

  int res = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (light[j][i]) res++;
    }
  }

  cout << res;
  return 0;
}