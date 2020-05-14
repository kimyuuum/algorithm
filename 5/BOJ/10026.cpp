#include <iostream>
#include <queue>
using namespace std;
const int MAX = 101;
char map[MAX][MAX];
bool visited[MAX][MAX];
bool visited2[MAX][MAX];
int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {-1, 0, 1, 0};
int n;

void bfs(int x, int y) {
  queue<pair<int, int>> q;
  q.push(make_pair(x, y));
  visited[x][y] = true;

  while (!q.empty()) {
    int curX = q.front().first;
    int curY = q.front().second;
    char color = map[curX][curY];
    q.pop();

    for (int i = 0; i < 4; i++) {
      int nextX = curX + dirX[i];
      int nextY = curY + dirY[i];

      if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= n) {
        continue;
      }
      if (visited[nextX][nextY] || map[nextX][nextY] != color) {
        continue;
      }

      q.push(make_pair(nextX, nextY));
      visited[nextX][nextY] = true;
    }
  }
}

void bfs2(int x, int y) {
  queue<pair<int, int>> q;
  q.push(make_pair(x, y));
  visited2[x][y] = true;

  while (!q.empty()) {
    int curX = q.front().first;
    int curY = q.front().second;
    char color = map[curX][curY];
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nextX = curX + dirX[i];
      int nextY = curY + dirY[i];

      if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= n) {
        continue;
      }
      if (visited2[nextX][nextY]) {
        continue;
      }
      if (color == 'R' || color == 'G') {
        if (map[nextX][nextY] == 'B') {
          continue;
        }
      } else if (color == 'B') {
        if (map[nextX][nextY] != color) {
          continue;
        }
      }

      q.push(make_pair(nextX, nextY));
      visited2[nextX][nextY] = true;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> map[j][i];
    }
  }
  int res1 = 0, res2 = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (!visited[j][i]) {
        bfs(j, i);
        res1++;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (!visited2[j][i]) {
        bfs2(j, i);
        res2++;
      }
    }
  }

  cout << res1 << " " << res2;
  return 0;
}