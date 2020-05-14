#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 26;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {-1, 0, 1, 0};
int n;
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

      if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= n) {
        continue;
      }
      if (visited[nextX][nextY] || map[nextX][nextY] == 0) {
        continue;
      }
      q.push(make_pair(nextX, nextY));
      visited[nextX][nextY] = true;
      size++;
    }
  }

  v.push_back(size);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char input;
      cin >> input;
      map[j][i] = input - '0';
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (map[j][i] == 1 && !visited[j][i]) {
        bfs(j, i);
      }
    }
  }

  sort(v.begin(), v.end());
  cout << v.size() << "\n";
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << "\n";
  }
  return 0;
}