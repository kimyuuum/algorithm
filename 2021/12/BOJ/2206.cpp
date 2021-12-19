#include <iostream>
#include <queue>
using namespace std;
const int MAX = 1001;
int wall[MAX][MAX][2] = {
    false,
};
int map[MAX][MAX] = {
    0,
};
int N, M;
int result = 987654321;
int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {-1, 0, 1, 0};

void bfs() {
  queue<pair<int, pair<int, int> > > q;
  q.push(make_pair(1, make_pair(0, 0)));
  //벽을 뚫을 수 있음
  wall[0][0][1] = 1;

  while (!q.empty()) {
    int curX = q.front().second.first;
    int curY = q.front().second.second;
    bool canGo = q.front().first;
    int curCnt = wall[curX][curY][canGo];

    q.pop();

    if (curX == N - 1 && curY == M - 1) {
      if (result > wall[curX][curY][canGo]) {
        result = wall[curX][curY][canGo];
      }
      continue;
    }

    for (int i = 0; i < 4; i++) {
      int nextX = curX + dirX[i];
      int nextY = curY + dirY[i];

      if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M) {
        continue;
      }

      if (map[nextX][nextY] == 1 && canGo == true) {
        if (wall[nextX][nextY][0] == 0) {
          wall[nextX][nextY][0] = wall[curX][curY][canGo] + 1;
          q.push(make_pair(0, make_pair(nextX, nextY)));
        }
      } else if (map[nextX][nextY] == 0) {
        if (wall[nextX][nextY][canGo] == 0) {
          wall[nextX][nextY][canGo] = wall[curX][curY][canGo] + 1;
          q.push(make_pair(canGo, make_pair(nextX, nextY)));
        }
      }
    }
  }

  return;
}
int main() {
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < s.size(); j++) {
      map[i][j] = s[j] - '0';
    }
  }

  bfs();
  if (result == 987654321) {
    cout << -1;
  } else {
    cout << result;
  }

  return 0;
}