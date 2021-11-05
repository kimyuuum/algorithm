#include <iostream>
using namespace std;
const int MAX = 1001;
int n, m;
int arr[MAX][MAX];
int d[MAX][MAX];
int dirX[3] = {1, 0, 1};
int dirY[3] = {0, 1, 1};

void bfs() {
  d[0][0] = arr[0][0];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int curX = i;
      int curY = j;
      for (int k = 0; k < 3; k++) {
        int nextX = dirX[k] + curX;
        int nextY = dirY[k] + curY;

        if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m) {
          continue;
        }

        int candy = arr[nextX][nextY];

        if (d[nextX][nextY] < candy + d[curX][curY]) {
          d[nextX][nextY] = candy + d[curX][curY];
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }

  bfs();
  cout << d[n - 1][m - 1];

  return 0;
}