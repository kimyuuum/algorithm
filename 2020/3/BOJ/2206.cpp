
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int MAX = 1001;
int map[MAX][MAX];
bool visited[MAX][MAX][2];
int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {-1, 0, 1, 0};
int n, m;

int bfs() {
  queue<pair<pair<int, int>, int> > q;
  q.push(make_pair(make_pair(0, 0), 0));
  visited[0][0][0] = true;
  int cnt = 1;

  while (!q.empty()) {
    int size = q.size();
    for (int s = 0; s < size; s++) {
      int curX = q.front().first.first;
      int curY = q.front().first.second;
      int curW = q.front().second;
      q.pop();
      if (curX == m - 1 && curY == n - 1) return cnt;

      if (curW == 0) {
        for (int i = 0; i < 4; i++) {
          int nextX = curX + dirX[i];
          int nextY = curY + dirY[i];
          int nextW = 1;
          if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n) continue;
          if (visited[nextX][nextY][nextW]) continue;
          q.push(make_pair(make_pair(nextX, nextY), nextW));
          visited[nextX][nextY][nextW] = true;
        }
      }

      for (int i = 0; i < 4; i++) {
        int nextX = curX + dirX[i];
        int nextY = curY + dirY[i];
        int nextW = curW;
        if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n) continue;
        if (map[nextX][nextY] || visited[nextX][nextY][nextW]) continue;
        q.push(make_pair(make_pair(nextX, nextY), nextW));
        visited[nextX][nextY][nextW] = true;
      }
    }
    cnt++;
  }

  return -1;
}

int main() {
  cin >> n >> m;
  string input;
  for (int i = 0; i < n; i++) {
    cin >> input;
    for (int j = 0; j < input.size(); j++) {
      map[j][i] = input[j] - '0';
    }
  }

  int result = bfs();
  cout << result;

  return 0;
}
