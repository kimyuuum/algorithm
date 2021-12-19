#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 21;
char map[MAX][MAX] = {
    0,
};
bool visited[MAX][MAX] = {
    false,
};
bool visAl[26] = {
    false,
};
int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {-1, 0, 1, 0};
int R, C, result = 0;

void dfs(int curX, int curY, int count) {
  int al = map[curX][curY] - 65;

  if (visited[curX][curY] || visAl[al]) {
    return;
  }

  visited[curX][curY] = true;
  visAl[al] = true;

  for (int i = 0; i < 4; i++) {
    int nextX = dirX[i] + curX;
    int nextY = dirY[i] + curY;

    if (nextX < 0 || nextX >= R || nextY < 0 || nextY >= C) {
      continue;
    }

    int nextAl = map[nextX][nextY] - 65;

    if (visited[nextX][nextY] || visAl[nextAl]) {
      continue;
    }

    dfs(nextX, nextY, count + 1);
    visited[nextX][nextY] = false;
    visAl[nextAl] = false;
  }

  if (result < count) {
    result = count;
  }

  visited[curX][curY] = false;
  visAl[al] = false;
  return;
}

int main() {
  cin >> R >> C;

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> map[i][j];
    }
  }

  dfs(0, 0, 1);

  cout << result;
}