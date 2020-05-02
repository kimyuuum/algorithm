
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int MAX = 6;
char map[MAX][MAX];
bool check[MAX][MAX];
bool visited[26];
int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {-1, 0, 1, 0};
int scnt, ycnt, res;

void bfs(int idx) {
  int x, y;
  if (idx % 5 == 0) {
    x = 4;
    if (idx == 5) {
      y = 0;
    } else {
      y = idx / 5 - 1;
    }
  } else {
    x = idx % 5 - 1;
    y = idx / 5;
  }

  if (map[x][y] == 'Y') {
    ycnt++;
  } else {
    scnt++;
  }

  queue<pair<int, int>> q;
  q.push(make_pair(x, y));
  check[x][y] = true;

  while (!q.empty()) {
    int curX = q.front().first;
    int curY = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int nextX = curX + dirX[i];
      int nextY = curY + dirY[i];
      int nIdx = nextX + (nextY * 5) + 1;

      if (nextX < 0 || nextX > 4 || nextY < 0 || nextY > 4) {
        continue;
      }
      if (!visited[nIdx] || check[nextX][nextY]) {
        continue;
      }

      q.push(make_pair(nextX, nextY));
      check[nextX][nextY] = true;
      if (map[nextX][nextY] == 'Y') {
        ycnt++;
      } else {
        scnt++;
      }
    }
  }
}
void dfs(int idx, int cnt) {
  if (cnt == 7) {
    scnt = 0;
    ycnt = 0;
    memset(check, false, sizeof(check));
    bfs(idx);
    if (scnt + ycnt == 7 && scnt >= 4) {
      res++;
    }
  } else {
    for (int i = idx + 1; i < 26; i++) {
      visited[i] = true;
      dfs(i, cnt + 1);
      visited[i] = false;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> map[j][i];
    }
  }

  for (int i = 1; i < 20; i++) {
    visited[i] = true;
    dfs(i, 1);
    visited[i] = false;
  }
  cout << res;
  return 0;
}