
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int MAX = 1000;
bool visited[MAX][MAX];
char map[MAX][MAX];
queue<pair<int, int>> fire;
int w, h;
int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {-1, 0, 1, 0};

int bfs(int x, int y) {
  int sec = 1;
  queue<pair<int, int>> q;
  q.push(make_pair(x, y));
  while (!q.empty()) {
    int fsize = fire.size();
    for (int f = 0; f < fsize; f++) {
      int curX = fire.front().first;
      int curY = fire.front().second;

      fire.pop();
      for (int i = 0; i < 4; i++) {
        int nextX = dirX[i] + curX;
        int nextY = dirY[i] + curY;
        if (nextX < 0 || nextX >= w || nextY < 0 || nextY >= h) continue;
        if (map[nextX][nextY] == '.' || map[nextX][nextY] == '@') {
          map[nextX][nextY] = '*';
          fire.push(make_pair(nextX, nextY));
        }
      }
    }

    int size = q.size();
    for (int s = 0; s < size; s++) {
      int curX = q.front().first;
      int curY = q.front().second;
      if (curX == w - 1 || curX == 0 || curY == h - 1 || curY == 0) {
        return sec;
      }
      q.pop();
      for (int i = 0; i < 4; i++) {
        int nextX = curX + dirX[i];
        int nextY = curY + dirY[i];

        if (nextX < 0 || nextX >= w || nextY < 0 || nextY >= h) continue;
        if (visited[nextX][nextY] || map[nextX][nextY] != '.') continue;
        q.push(make_pair(nextX, nextY));
        visited[nextX][nextY] = true;
      }
    }

    sec++;
  }
  return -1;
}
int main() {
  int testcase;
  cin >> testcase;
  while (testcase--) {
    memset(map, 0, sizeof(map));
    memset(visited, false, sizeof(visited));
    fire = {};
    cin >> w >> h;
    int x, y;
    string input;
    for (int i = 0; i < h; i++) {
      cin >> input;
      for (int j = 0; j < input.size(); j++) {
        map[j][i] = input[j];
        if (map[j][i] == '@') {
          x = j;
          y = i;
        }
        if (map[j][i] == '*') {
          fire.push(make_pair(j, i));
        }
      }
    }

    int res = bfs(x, y);
    if (res == -1) {
      cout << "IMPOSSIBLE\n";
    } else {
      cout << res << "\n";
    }
  }

  return 0;
}