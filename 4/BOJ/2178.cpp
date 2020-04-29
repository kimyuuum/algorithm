
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int MAX = 101;
int maze[MAX][MAX];
bool visited[MAX][MAX];
int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {-1, 0, 1, 0};
queue<pair<int, int>> q;
int n, m, res;

int bfs(int x, int y) {
  q.push(make_pair(x, y));
  visited[x][y] = true;
  int cnt = 1;

  while (!q.empty()) {
    int size = q.size();
    for (int s = 0; s < size; s++) {
      int curX = q.front().first;
      int curY = q.front().second;

      q.pop();

      if (curX == n && curY == m) {
        return cnt;
      }

      for (int i = 0; i < 4; i++) {
        int nextX = curX + dirX[i];
        int nextY = curY + dirY[i];

        if (nextX < 1 || nextX > n || nextY < 1 || nextY > m) {
          continue;
        }
        if (!maze[nextX][nextY]) {
          continue;
        }
        if (visited[nextX][nextY]) {
          continue;
        }
        visited[nextX][nextY] = true;
        q.push(make_pair(nextX, nextY));
      }
    }
    cnt++;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  string input;
  for (int i = 1; i <= n; i++) {
    cin >> input;
    for (int j = 0; j < input.size(); j++) {
      maze[i][j + 1] = input[j] - '0';
    }
  }

  cout << bfs(1, 1);

  return 0;
}