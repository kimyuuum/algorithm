#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int MAX = 1001;
int m, n, result = 0, nonTomato = 0;
queue<pair<int, int> > q;
int map[MAX][MAX] = {
    -1,
};
bool visited[MAX][MAX] = {
    false,
};
int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {-1, 0, 1, 0};

void bfs() {
  while (1) {
    queue<pair<int, int> > q2;

    while (!q.empty()) {
      int curX = q.front().first;
      int curY = q.front().second;
      q.pop();

      visited[curX][curY] = true;

      for (int i = 0; i < 4; i++) {
        int nextX = curX + dirX[i];
        int nextY = curY + dirY[i];

        if (nextX < m && nextX >= 0 && nextY < n && nextY >= 0) {
          if (map[nextX][nextY] == 0 && visited[nextX][nextY] == false) {
            q2.push(make_pair(nextX, nextY));
            visited[nextX][nextY] = true;
          }
        }
      }
    }

    q = q2;

    while (!q2.empty()) {
      int x = q2.front().first;
      int y = q2.front().second;

      map[x][y] = 1;
      q2.pop();
    }

    if (q.empty()) {
      break;
    } else {
      result++;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> m >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int num;
      cin >> num;
      map[j][i] = num;
      if (num == 1) {
        q.push(make_pair(j, i));
      } else if (num == -1) {
        nonTomato++;
      }
    }
  }

  if (m * n - nonTomato == q.size()) {
    cout << 0;
  } else {
    bfs();

    bool imPossible = false;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (map[j][i] == 0) {
          imPossible = true;
          break;
        }
      }
      if (imPossible) {
        break;
      }
    }

    if (imPossible) {
      cout << -1;
    } else {
      cout << result;
    }
  }

  return 0;
}