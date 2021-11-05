#include <iostream>
#include <queue>
using namespace std;
const int MAX = 1005;
int map[MAX][MAX];
long long d[MAX][MAX];
int n, m;
int dirX[3] = {1, 0, 1};
int dirY[3] = {0, 1, 1};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> map[j][i];
    }
  }

  d[1][1] = map[1][1];

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int k = 0; k < 3; k++) {
        int nextX = j + dirX[k];
        int nextY = i + dirY[k];

        if (d[nextX][nextY] < map[nextX][nextY] + d[j][i]) {
          d[nextX][nextY] = map[nextX][nextY] + d[j][i];
        }
      }
    }
  }

  cout << d[m][n];
  return 0;
}