
#include <iostream>
#include <queue>
using namespace std;
const int MAX = 22;
char map[MAX][MAX];
bool arr[26];
int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {-1, 0, 1, 0};
int r, c;
int cnt = 1;

void dfs(int x, int y, int count) {
  if (count > cnt) {
    cnt = count;
    if (count == 26) {
      cout << 26;
      exit(0);
    }
  }

  char al = map[x][y];
  arr[al - 65] = true;
  for (int i = 0; i < 4; i++) {
    int nextX = x + dirX[i];
    int nextY = y + dirY[i];
    if (nextX < 1 || nextX > c || nextY < 1 || nextY > r) {
      continue;
    }
    char nal = map[nextX][nextY];
    if (!arr[nal - 65]) {
      arr[nal - 65] = true;
      dfs(nextX, nextY, count + 1);
      arr[nal - 65] = false;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> r >> c;
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      cin >> map[j][i];
    }
  }

  dfs(1, 1, 1);

  cout << cnt;
  return 0;
}