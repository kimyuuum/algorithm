
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int MAX = 1501;
char map[MAX][MAX];
bool visited[MAX][MAX];
int r, c;
queue<pair<int, int>> swan;
queue<pair<int, int>> water;
int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {-1, 0, 1, 0};

int bfs() {
  queue<pair<int, int>> q;
  int swanX = swan.front().first;
  int swanY = swan.front().second;
  q.push(make_pair(swanX, swanY));
  visited[swanX][swanY] = true;
  swan.pop();
  int day = 0;

  while (1) {
    bool flag = false;
    queue<pair<int, int>> nextQ;

    while (!q.empty()) {
      int curX = q.front().first;
      int curY = q.front().second;
      q.pop();

      if (curX == swan.front().first && curY == swan.front().second) {
        flag = true;
        break;
      }

      for (int i = 0; i < 4; i++) {
        int nextX = curX + dirX[i];
        int nextY = curY + dirY[i];
        if (nextX < 0 || nextX >= c || nextY < 0 || nextY >= r) continue;
        if (visited[nextX][nextY]) continue;

        if (map[nextX][nextY] == 'X') {
          nextQ.push(make_pair(nextX, nextY));
          continue;
        }
        q.push(make_pair(nextX, nextY));
        visited[nextX][nextY] = true;
      }
    }

    if (flag) break;
    q = nextQ;

    int size = water.size();
    for (int s = 0; s < size; s++) {
      int curX = water.front().first;
      int curY = water.front().second;
      water.pop();

      for (int i = 0; i < 4; i++) {
        int nextX = curX + dirX[i];
        int nextY = curY + dirY[i];

        if (nextX < 0 || nextX >= c || nextY < 0 || nextY >= r) continue;
        if (visited[nextX][nextY]) continue;
        if (map[nextX][nextY] == 'X') {
          map[nextX][nextY] = '.';
          water.push(make_pair(nextX, nextY));
        }
      }
    }
    day++;
  }

  return day;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> r >> c;
  string input;

  for (int i = 0; i < r; i++) {
    cin >> input;
    for (int j = 0; j < input.size(); j++) {
      map[j][i] = input[j];
      if (input[j] == 'L') {
        swan.push(make_pair(j, i));
        water.push(make_pair(j, i));
      } else if (input[j] == '.') {
        water.push(make_pair(j, i));
      }
    }
  }

  int res = bfs();

  cout << res;

  return 0;
}