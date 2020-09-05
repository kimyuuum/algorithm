//불!
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int MAX = 1005;
int res = -1;
int r, c;
char map[MAX][MAX];
bool visited[MAX][MAX];
int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {-1, 0, 1, 0};
queue<pair<int, int>> fire;
queue<pair<pair<int, int>, int>> q;

void bfs() {
  while (!q.empty()) {
    int fsize = fire.size();
    for (int s = 0; s < fsize; s++) {
      int fireX = fire.front().first;
      int fireY = fire.front().second;

      fire.pop();

      for (int i = 0; i < 4; i++) {
        int nFireX = fireX + dirX[i];
        int nFireY = fireY + dirY[i];

        if (nFireX < 0 || nFireX >= r || nFireY < 0 || nFireY >= c) {
          continue;
        }
        if (map[nFireX][nFireY] == '.' || map[nFireX][nFireY] == 'J') {
          map[nFireX][nFireY] = 'F';
          fire.push(make_pair(nFireX, nFireY));
        }
      }
    }

    int qsize = q.size();
    for (int s = 0; s < qsize; s++) {
      int curX = q.front().first.first;
      int curY = q.front().first.second;
      int cnt = q.front().second;

      visited[curX][curY] = true;
      q.pop();

      if (curX == 0 || curX == r - 1 || curY == 0 || curY == c - 1) {
        if (res == -1) {
          res = cnt;
        } else {
          if (res > cnt) {
            res = cnt;
          }
        }
        continue;
      }
      for (int i = 0; i < 4; i++) {
        int nextX = curX + dirX[i];
        int nextY = curY + dirY[i];

        if (nextX < 0 || nextX >= r || nextY < 0 || nextY >= c) {
          continue;
        }
        if (map[nextX][nextY] == '.' && !visited[nextX][nextY]) {
          q.push({make_pair(nextX, nextY), cnt + 1});
          visited[nextX][nextY] = true;
        }
      }
    }

  }
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> r >> c;
  for (int i = 0; i < r; i++) {
    string input;
    cin >> input;

    for (int j = 0; j < input.size(); j++) {
      map[i][j] = input[j];
      if (input[j] == 'J') {
        q.push({make_pair(i, j), 0});
      } else if (input[j] == 'F') {
        fire.push(make_pair(i, j));
      }
    }
  }

  bfs();

  if (res == -1) {
    cout << "IMPOSSIBLE";
  } else {
    cout << res + 1;
  }

  return 0;
}