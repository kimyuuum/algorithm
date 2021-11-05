//탈출
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int MAX = 55;
int r, c, res = 0;
char map[MAX][MAX];
bool visited[MAX][MAX] = {
    false,
};
int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {-1, 0, 1, 0};

queue<pair<int, int>> q;
queue<pair<int, int>> water;

void bfs() {
  int cnt = 0;

  while (!q.empty()) {
    int wsize = water.size();
    for (int w = 0; w < wsize; w++) {
      int waterX = water.front().first;
      int waterY = water.front().second;
      water.pop();

      for (int i = 0; i < 4; i++) {
        int nextX = waterX + dirX[i];
        int nextY = waterY + dirY[i];

        if (nextX < 0 || nextX >= r || nextY < 0 || nextY >= c) {
          continue;
        }

        if (map[nextX][nextY] == 'D' || map[nextX][nextY] == 'X' || map[nextX][nextY] == '*') {
          continue;
        }

        water.push(make_pair(nextX, nextY));
        map[nextX][nextY] = '*';
      }
    }

    int qsize = q.size();

    for (int s = 0; s < qsize; s++) {
      int curX = q.front().first;
      int curY = q.front().second;
      q.pop();

      if (map[curX][curY] == 'D') {
        res = cnt;
        break;
      }

      for (int i = 0; i < 4; i++) {
        int nextX = curX + dirX[i];
        int nextY = curY + dirY[i];

        if (nextX < 0 || nextX >= r || nextY < 0 || nextY >= c) {
          continue;
        }

        if (visited[nextX][nextY] || map[nextX][nextY] == 'X' ||
            map[nextX][nextY] == '*') {
          continue;
        }

        q.push(make_pair(nextX, nextY));
        visited[nextX][nextY] = true;
      }
    }

    cnt++;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> r >> c;
  for (int i = 0; i < r; i++) {
    string input;
    cin >> input;
    for (int j = 0; j < input.size(); j++) {
      map[i][j] = input[j];
      if (input[j] == 'S') {
        q.push(make_pair(i, j));
      } else if (input[j] == '*') {
        water.push(make_pair(i, j));
      }
    }
  }

  bfs();
  if (res == 0) {
    cout << "KAKTUS";
  } else {
    cout << res;
  }
  return 0;
}