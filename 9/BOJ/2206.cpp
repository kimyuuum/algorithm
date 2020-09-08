//벽 부수고 이동하기
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int MAX = 1005;
char map[MAX][MAX];
bool visited[2][MAX][MAX] = {
    false,
};
int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {-1, 0, 1, 0};
int n, m;

int bfs() {
  queue<pair<pair<int, int>, pair<bool, int>>> q;
  q.push({make_pair(0, 0), make_pair(false, 0)});
  visited[0][0][0] = true;

  while (!q.empty()) {
    int curX = q.front().first.first;
    int curY = q.front().first.second;
    bool wall = q.front().second.first;
    int cnt = q.front().second.second;
    q.pop();

    if (curX == n - 1 && curY == m - 1) {
      return cnt + 1;
    }

    if (!wall) {
      for (int i = 0; i < 4; i++) {
        int nextX = curX + dirX[i];
        int nextY = curY + dirY[i];

        if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m) {
          continue;
        }

        if (map[nextX][nextY] == '1' && !visited[1][nextX][nextY]) {
          q.push({make_pair(nextX, nextY), {true, cnt + 1}});
          visited[1][nextX][nextY] = true;
        }
      }
    }

    for (int i = 0; i < 4; i++) {
      int nextX = curX + dirX[i];
      int nextY = curY + dirY[i];

      if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m) {
        continue;
      }

      if (map[nextX][nextY] == '0' && !visited[wall][nextX][nextY]) {
        q.push({make_pair(nextX, nextY), {wall, cnt + 1}});
        visited[wall][nextX][nextY] = true;
      }
    }
  }

  return -1;
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    string input;
    cin >> input;
    for (int j = 0; j < input.size(); j++) {
      map[i][j] = input[j];
    }
  }

  cout << bfs();

  return 0;
}