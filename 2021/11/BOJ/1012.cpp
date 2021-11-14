#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int MAX = 51;
int T, m, n, k, result = 0;
bool map[MAX][MAX] = {
    0,
};
bool visited[MAX][MAX] = {
    false,
};

int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {-1, 0, 1, 0};

void bfs(int x, int y) {
  queue<pair<int, int> > q;
  q.push(make_pair(x, y));
  visited[x][y] = true;

  while (!q.empty()) {
    int curX = q.front().first;
    int curY = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int nextX = curX + dirX[i];
      int nextY = curY + dirY[i];

      if (nextX < m && nextX >= 0 && nextY < n && nextY >= 0) {
        if (map[nextX][nextY] == 1 && visited[nextX][nextY] == false) {
          q.push(make_pair(nextX, nextY));
          visited[nextX][nextY] = true;
        }
      }
    }
  }

  result++;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;

  while (T--) {
    result = 0;
    cin >> m >> n >> k;

    for (int i = 0; i < k; i++) {
      int x, y;
      cin >> x >> y;
      map[x][y] = 1;
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (map[j][i] == 1 && visited[j][i] == false) {
          bfs(j, i);
        }
      }
    }

    cout << result << "\n";

    memset(map, 0, sizeof(map));
    memset(visited, false, sizeof(visited));
  }

  return 0;
}
