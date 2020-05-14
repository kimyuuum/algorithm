#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int MAX = 303;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dirX[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dirY[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int l;

int bfs(int a, int b, int x, int y) {
  queue<pair<int, pair<int, int>>> q;
  q.push(make_pair(0, make_pair(a, b)));
  visited[a][b] = true;
  int cnt = 0;

  while (!q.empty()) {
    int curX = q.front().second.first;
    int curY = q.front().second.second;
    int cnt = q.front().first;
    q.pop();

    if (curX == x && curY == y) {
      return cnt;
    }

    for (int i = 0; i < 8; i++) {
      int nextX = curX + dirX[i];
      int nextY = curY + dirY[i];
      if (nextX < 0 || nextX >= l || nextY < 0 || nextY >= l) {
        continue;
      }
      if (visited[nextX][nextY]) {
        continue;
      }
      q.push(make_pair(cnt + 1, make_pair(nextX, nextY)));
      visited[nextX][nextY] = true;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int testcase;
  cin >> testcase;
  while (testcase--) {
    cin >> l;
    memset(visited, false, sizeof(visited));
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    cout << bfs(a, b, x, y) << "\n";
  }

  return 0;
}