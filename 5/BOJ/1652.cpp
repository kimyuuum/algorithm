#include <cstring>
#include <iostream>
using namespace std;
const int MAX = 101;
char map[MAX][MAX];
bool visited[MAX][MAX];
int xcnt = 0, ycnt = 0;
int n;
int checkX(int x, int y) {
  int cnt = 1;
  visited[x][y] = true;

  while (1) {
    x++;
    if (x >= n) {
      return cnt;
    }
    if (map[x][y] == 'X') {
      return cnt;
    }
    visited[x][y] = true;
    cnt++;
  }
}
int checkY(int x, int y) {
  int cnt = 1;
  visited[x][y] = true;

  while (1) {
    y++;
    if (y >= n) {
      return cnt;
    }
    if (map[x][y] == 'X') {
      return cnt;
    }
    visited[x][y] = true;
    cnt++;
  }
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> map[j][i];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (!visited[j][i] && map[j][i] == '.') {
        int res = checkX(j, i);
        if (res >= 2) {
          xcnt++;
        }
      }
    }
  }
  memset(visited, false, sizeof(visited));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (!visited[j][i] && map[j][i] == '.') {
        int res = checkY(j, i);
        if (res >= 2) {
          ycnt++;
        }
      }
    }
  }
  cout << xcnt << " " << ycnt;
  return 0;
}