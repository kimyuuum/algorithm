#include <iostream>
#include <queue>
using namespace std;
const int MAX = 51;
bool visited[MAX][MAX] = {
    false,
};
int n, m, result = 0;
queue<pair<int, int> > q;
int map[MAX][MAX] = {
    0,
};
int dirX[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dirY[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int bfs() {
  int cnt = 0;

  while (!q.empty()) {
    queue<pair<int, int> > q2;
    int size = q.size();
    for (int i = 0; i < size; i++) {
      int curX = q.front().first;
      int curY = q.front().second;
      visited[curX][curY] = true;

      q.pop();

      for (int i = 0; i < 8; i++) {
        int nextX = curX + dirX[i];
        int nextY = curY + dirY[i];

        if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m) {
          continue;
        }

        if (map[nextX][nextY] == 1 || visited[nextX][nextY]) {
          continue;
        }

        q2.push(make_pair(nextX, nextY));
        visited[nextX][nextY] = true;
      }
    }
    if (q2.empty()) {
      return cnt;
    }
    cnt++;
    q = q2;
  }

  return cnt;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> map[i][j];
      if (map[i][j] == 1) {
        q.push(make_pair(i, j));
      }
    }
  }

  cout << bfs();

  return 0;
}