#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int MAX = 51;
int map[MAX][MAX];
int n, l, r;
bool visited[MAX][MAX];
int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {-1, 0, 1, 0};

bool bfs(int x, int y) {
  queue<pair<int, int>> q;
  queue<pair<int, int>> country;

  int sum = map[x][y];
  int cnt = 1;

  bool moved = false;
  visited[x][y] = true;
  q.push(make_pair(x, y));
  country.push({x, y});

  while (!q.empty()) {
    int curX = q.front().first;
    int curY = q.front().second;
    // cout << map[curX][curY] << " ";
    q.pop();

    for (int i = 0; i < 4; i++) {
      int nextX = curX + dirX[i];
      int nextY = curY + dirY[i];

      if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= n) {
        continue;
      }

      int diff = abs(map[curX][curY] - map[nextX][nextY]);
      // cout << map[nextX][nextY] << " " << diff << endl;
      if (!visited[nextX][nextY] && (diff >= l && diff <= r)) {
        visited[nextX][nextY] = true;
        q.push(make_pair(nextX, nextY));
        country.push(make_pair(nextX, nextY));
        moved = true;
        cnt++;
        sum += map[nextX][nextY];
      }
    }
  }

  if (cnt != 1) {
    sum /= cnt;
    while (!country.empty()) {
      int curX = country.front().first;
      int curY = country.front().second;

      map[curX][curY] = sum;
      country.pop();
    }
  }

  return moved;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> l >> r;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> map[j][i];
    }
  }

  int res = 0;

  while (1) {
    memset(visited, false, sizeof(visited));
    bool moved = false;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (!visited[j][i]) {
          if (bfs(j, i)) {
            moved = true;
          }
        }
      }
    }
    // for (int a = 0; a < n; a++) {
    //   for (int b = 0; b < n; b++) {
    //     cout << map[b][a] << " ";
    //   }
    //   cout << endl;
    // }

    if (!moved) {
      break;
    }
    res++;
  }

  cout << res;
  return 0;
}

// 국경 열어서 지역 구한다 -> bfs로 연합 구한다
// update
