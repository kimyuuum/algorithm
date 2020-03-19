
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int MAX = 1501;
int r, c;
char map[MAX][MAX];
bool visited[MAX][MAX];
int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {-1, 0, 1, 0};
queue<pair<int, int>> swan;
queue<pair<int, int>> water;

int bfs() {
  queue<pair<int, int>> q;
  int swanx = swan.front().first;
  int swany = swan.front().second;
  swan.pop();
  q.push(make_pair(swanx, swany));
  visited[swanx][swany] = true;

  int day = 0;

  while (1) {
    queue<pair<int, int>> nextQ;
    bool flag = false;

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
        visited[nextX][nextY] = true;
        if (map[nextX][nextY] == 'X') {
          nextQ.push(make_pair(nextX, nextY));
          continue;
        }
        q.push(make_pair(nextX, nextY));
      }
    }

    if (flag) break;
    q = nextQ;

    int size = water.size();
    for (int j = 0; j < size; j++) {
      int x = water.front().first;
      int y = water.front().second;
      water.pop();

      for (int i = 0; i < 4; i++) {
        int nextX = x + dirX[i];
        int nextY = y + dirY[i];

        if (nextX < 0 || nextX >= c || nextY < 0 || nextY >= r) continue;
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
      if (map[j][i] == 'L') {
        swan.push(make_pair(j, i));
        water.push(make_pair(j, i));
      } else if (map[j][i] == '.')
        water.push(make_pair(j, i));
    }
  }

  int result = bfs();
  cout << result;

  return 0;
}