
#include <iostream>
#include <queue>
using namespace std;
const int MAX = 51;
int map[MAX][MAX];
bool visited[MAX][MAX];
int n, m, r, c, d, clean;
vector<int> dirX[4];
vector<int> dirY[4];
queue<pair<int, pair<int, int>>> q;

void bfs() {
  visited[c][r] = true;
  clean++;
  q.push(make_pair(d, make_pair(c, r)));

  while (!q.empty()) {
    int curX = q.front().second.first;
    int curY = q.front().second.second;
    int curD = q.front().first;
    int nextD = curD;
    bool flag = false;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nextX = curX + dirX[curD][i];
      int nextY = curY + dirY[curD][i];
      nextD--;
      if (nextD < 0) {
        nextD = 3;
      }
      if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n) {
        continue;
      }

      if (map[nextX][nextY] != 1 && !visited[nextX][nextY]) {
        q.push(make_pair(nextD, make_pair(nextX, nextY)));
        visited[nextX][nextY] = true;
        clean++;
        flag = true;
        break;
      }
    }

    if (!flag) {
      int nextX, nextY;
      if (curD == 0) {
        nextX = curX;
        nextY = curY + 1;
      } else if (curD == 1) {
        nextX = curX - 1;
        nextY = curY;
      } else if (curD == 2) {
        nextX = curX;
        nextY = curY - 1;
      } else {
        nextX = curX + 1;
        nextY = curY;
      }

      if (nextX >= 0 && nextX < m && nextY >= 0 && nextY < n) {
        if (map[nextX][nextY] != 1) {
          q.push(make_pair(curD, make_pair(nextX, nextY)));
          if (!visited[nextX][nextY]) {
            visited[nextX][nextY] = true;
            clean++;
          }
        }
      } else {
        return;
      }
    }
  }
}
int main() {
  cin >> n >> m;
  cin >> r >> c >> d;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> map[j][i];
    }
  }

  dirX[0] = {-1, 0, 1, 0};
  dirY[0] = {0, 1, 0, -1};
  dirX[1] = {0, -1, 0, 1};
  dirY[1] = {-1, 0, 1, 0};
  dirX[2] = {1, 0, -1, 0};
  dirY[2] = {0, -1, 0, 1};
  dirX[3] = {0, 1, 0, -1};
  dirY[3] = {1, 0, -1, 0};

  bfs();
  cout << clean;
  return 0;
}