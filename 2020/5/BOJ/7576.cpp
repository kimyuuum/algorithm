
#include <iostream>
#include <queue>
using namespace std;
const int MAX = 1005;
int n, m, day;
int map[MAX][MAX];
int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {-1, 0, 1, 0};
queue<pair<int, int>> q;

int bfs() {
  while (!q.empty()) {
    int size = q.size();
    for (int i = 0; i < size; i++) {
      int curX = q.front().first;
      int curY = q.front().second;
      q.pop();

      for (int i = 0; i < 4; i++) {
        int nextX = curX + dirX[i];
        int nextY = curY + dirY[i];

        if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n) {
          continue;
        }

        if (map[nextX][nextY] == 0) {
          q.push(make_pair(nextX, nextY));
          map[nextX][nextY] = 1;
        }
      }
    }
    day++;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (map[j][i] == 0) {
        return -1;
      }
    }
  }

  return day - 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> m >> n;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> map[j][i];
      if (map[j][i] == 1) {
        q.push(make_pair(j, i));
      } else if (map[j][i] == 0) {
        cnt++;
      }
    }
  }

  if (cnt == 0) {
    cout << 0;
  } else {
    day = bfs();
    cout << day;
  }
  return 0;
}