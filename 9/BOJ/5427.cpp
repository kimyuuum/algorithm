//불
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int MAX = 1005;
char map[MAX][MAX];
bool visited[MAX][MAX];
int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {-1, 0, 1, 0};
int testcase, w, h;
queue<pair<int, int>> fire;

int bfs(int x, int y) {
  queue<pair<int, int>> q;
  q.push(make_pair(x, y));
  visited[x][y] = true;
  int cnt = 1;

  while (!q.empty()) {
    // fire
    int fsize = fire.size();
    for (int s = 0; s < fsize; s++) {
      int curX = fire.front().first;
      int curY = fire.front().second;

      fire.pop();

      for (int i = 0; i < 4; i++) {
        int nextX = curX + dirX[i];
        int nextY = curY + dirY[i];

        if (nextX < 0 || nextX >= h || nextY < 0 || nextY >= w) {
          continue;
        }

        if (map[nextX][nextY] == '@' || map[nextX][nextY] == '.') {
          map[nextX][nextY] = '*';
          fire.push(make_pair(nextX, nextY));
        }
      }
    }

    int qsize = q.size();
    for (int s = 0; s < qsize; s++) {
      int curX = q.front().first;
      int curY = q.front().second;

      q.pop();

      if (curX == h - 1 || curX == 0 || curY == w - 1 || curY == 0) {
        return cnt;
      }

      for (int i = 0; i < 4; i++) {
        int nextX = curX + dirX[i];
        int nextY = curY + dirY[i];

        if (nextX < 0 || nextX >= h || nextY < 0 || nextY >= w) {
          continue;
        }

        if (map[nextX][nextY] == '.' && !visited[nextX][nextY]) {
          q.push(make_pair(nextX, nextY));
          visited[nextX][nextY] = true;
        }
      }
    }

    cnt++;
  }

  return -1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> testcase;
  while (testcase--) {
    memset(map, 0, sizeof(map));
    memset(visited, false, sizeof(visited));
    fire = {};

    int x, y;
    cin >> w >> h;

    for (int i = 0; i < h; i++) {
      string input;
      cin >> input;
      for (int j = 0; j < input.size(); j++) {
        map[i][j] = input[j];
        if (input[j] == '@') {
          x = i;
          y = j;
        } else if (input[j] == '*') {
          fire.push({i, j});
        }
      }
    }

    int res = bfs(x, y);
    if (res == -1) {
      cout << "IMPOSSIBLE\n";
    } else {
      cout << res << endl;
    }
  }

  return 0;
}