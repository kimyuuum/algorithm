#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 105;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {-1, 0, 1, 0};
int m, n, k;
vector<int> v;

void bfs(int x, int y) {
  int size = 1;
  queue<pair<int, int>> q;
  visited[x][y] = true;
  q.push(make_pair(x, y));

  while (!q.empty()) {
    int curX = q.front().first;
    int curY = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int nextX = curX + dirX[i];
      int nextY = curY + dirY[i];

      if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m) {
        continue;
      }
      if (visited[nextX][nextY] || map[nextX][nextY] == 1) {
        continue;
      }
      visited[nextX][nextY] = true;
      q.push(make_pair(nextX, nextY));
      size++;
    }
  }
  v.push_back(size);
}

int main() {
  cin >> m >> n >> k;

  for (int i = 0; i < k; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for (int i = b; i < d; i++) {
      for (int j = a; j < c; j++) {
        if (map[j][i] != 1) {
          map[j][i] = 1;
        }
      }
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (map[j][i] == 0 && !visited[j][i]) {
        bfs(j, i);
      }
    }
  }

  sort(v.begin(), v.end());
  cout << v.size() << "\n";
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  return 0;
}