
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int MAX = 105;
int map[MAX][MAX];
bool visited[MAX][MAX] = {
    false,
};
int cheeze[MAX][MAX] = {
    -1,
};
int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {-1, 0, 1, 0};

int n, m;

int airDfs(int x, int y) {
  visited[x][y] = true;
  cheeze[x][y] = 0;
  queue<pair<int, int>> q;
  q.push({x, y});
  int melt = 0;
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

      if (!visited[nextX][nextY]) {
        if (map[nextX][nextY] == 1) {
          cheeze[nextX][nextY] = 1;
          visited[nextX][nextY] = true;
          melt++;
        } else if (map[nextX][nextY] == 0) {
          visited[nextX][nextY] = true;
          q.push(make_pair(nextX, nextY));
        }
      }
    }
  }

  return melt;
}

int dfs(int x, int y) {
  queue<pair<int, int>> q;
  q.push(make_pair(x, y));
  visited[x][y] = true;
  int cheeze = 0;

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

      if (!visited[nextX][nextY] && map[nextX][nextY] == 1) {
        q.push(make_pair(nextX, nextY));
        visited[nextX][nextY] = true;
      }
    }
    cheeze++;
  }

  return cheeze;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> map[i][j];
    }
  }
  int res = 0;
  int cres = 0;
  while (1) {
    memset(visited, false, sizeof(visited));
    memset(cheeze, -1, sizeof(cheeze));
    int melt = airDfs(0, 0);
    memset(visited, false, sizeof(visited));
    int whole = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!visited[i][j] && map[i][j] == 1) {
          whole += dfs(i, j);
        }
      }
    }
    res++;
    if (whole == melt) {
      cres = melt;
      break;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (cheeze[i][j] == 1) {
          map[i][j] = 0;
        }
      }
    }
  }

  cout << res<<"\n"<<cres;
  return 0;
}