//말이 되고픈 원숭이

#include <iostream>
#include <queue>
using namespace std;
const int MAX = 202;
const int KMAX = 33;
int hdirX[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
int hdirY[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {-1, 0, 1, 0};
int w, h, k;
int res = 987654321;
int map[MAX][MAX];
bool visited[KMAX][MAX][MAX] = {
    false,
};

void bfs() {
  queue<pair<pair<int, int>, pair<int, int>>> q;
  q.push({make_pair(0, 0), make_pair(0, 0)});
  visited[0][0][0] = true;

  while (!q.empty()) {
    int curX = q.front().first.first;
    int curY = q.front().first.second;
    int jump = q.front().second.first;
    int cnt = q.front().second.second;
    q.pop();

    if (curX == h - 1 && curY == w - 1) {
      if (res > cnt) {
        res = cnt;
      }
      continue;
    }

    if (jump < k) {
      for (int i = 0; i < 8; i++) {
        int nextX = curX + hdirX[i];
        int nextY = curY + hdirY[i];
        int njump = jump + 1;

        if (nextX < 0 || nextX >= h || nextY < 0 || nextY >= w) {
          continue;
        }
        if (map[nextX][nextY] == 1 || visited[njump][nextX][nextY]) {
          continue;
        }

        q.push({make_pair(nextX, nextY), make_pair(njump, cnt + 1)});
        visited[njump][nextX][nextY] = true;
      }
    }
    for (int i = 0; i < 4; i++) {
      int nextX = curX + dirX[i];
      int nextY = curY + dirY[i];

      if (nextX < 0 || nextX >= h || nextY < 0 || nextY >= w) {
        continue;
      }
      if (map[nextX][nextY] == 1 || visited[jump][nextX][nextY]) {
        continue;
      }

      q.push({make_pair(nextX, nextY), make_pair(jump, cnt + 1)});
      visited[jump][nextX][nextY] = true;
    }
  }
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> k >> w >> h;

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> map[i][j];
    }
  }

  bfs();

  if (res == 987654321) {
    cout << -1;
  } else {
    cout << res;
  }
}