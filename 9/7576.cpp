#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 1005;
int arr[MAX][MAX];
int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {-1, 0, 1, 0};
queue<pair<int, int>> q;
int m, n, a, day = 0;

void bfs() {
  while (!q.empty()) {
    int size = q.size();
    for (int s = 0; s < size; s++) {
      int curX = q.front().first;
      int curY = q.front().second;

      q.pop();

      for (int i = 0; i < 4; i++) {
        int nextX = curX + dirX[i];
        int nextY = curY + dirY[i];

        if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m) {
          continue;
        }
        if (arr[nextX][nextY] == 0) {
          q.push(make_pair(nextX, nextY));
          arr[nextX][nextY] = 1;
        }
      }
    }

    day++;
  }

  day--;
}

bool isAllRipe() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] == 0) {
        return false;
      }
    }
  }

  return true;
}

int main() {
  cin >> m >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
      if (arr[i][j] == 1) {
        q.push(make_pair(i, j));
      }
    }
  }

  if (isAllRipe()) {
    cout << 0;
  } else {
    bfs();

    if (isAllRipe()) {
      cout << day;
    } else {
      cout << -1;
    }
  }

  return 0;
}