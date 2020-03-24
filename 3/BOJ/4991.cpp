#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 21;
bool visited[MAX][MAX];
int map[MAX][MAX];
int dist[12][12];
int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {-1, 0, 1, 0};
int w, h;
int x, y;

void bfs(int x, int y, int idx) {
  memset(visited, false, sizeof(visited));
  queue<pair<pair<int, int>, int>> q;
  q.push(make_pair(make_pair(x, y), 0));

  while (!q.empty()) {
    int curX = q.front().first.first;
    int curY = q.front().first.second;
    int dis = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int nextX = curX + dirX[i];
      int nextY = curY + dirY[i];

      if (nextX < 0 || nextX >= w || nextY < 0 || nextY >= h) continue;
      if (visited[nextX][nextY] || map[nextX][nextY] == -1) continue;
      if (map[nextX][nextY] > idx) {
        int cnt = map[nextX][nextY];
        dist[cnt][idx] = dis + 1;
        dist[idx][cnt] = dis + 1;
      }
      q.push(make_pair(make_pair(nextX, nextY), dis + 1));
      visited[nextX][nextY] = true;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  while (1) {
    memset(map, 0, sizeof(map));
    memset(dist, 0, sizeof(dist));
    queue<pair<int, int>> q;
    int cnt = 0;
    cin >> w >> h;
    if (w == 0 && h == 0) {
      break;
    }

    char input;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        cin >> input;
        if (input == 'o') {
          x = j, y = i;
        } else if (input == '*') {
          map[j][i] = ++cnt;
          q.push(make_pair(j, i));
        } else if (input == 'x') {
          map[j][i] = -1;
        }
      }
    }

    bfs(x, y, 0);
    
    for (int i = 1; i <= cnt; i++) {
      int dx = q.front().first;
      int dy = q.front().second;
      bfs(dx, dy, i);
      q.pop();
    }

    vector<int> v;

    for (int i = 1; i <= cnt; i++) {
      v.push_back(i);
    }

    bool flag = false;
    int res = 987654321;
    do {
      int sum = dist[0][v[0]];
      if (sum == 0) {
        flag = true;
      }
      for (int i = 0; i < cnt - 1; i++) {
        sum += dist[v[i]][v[i + 1]];
        if (dist[v[i]][v[i + 1]] == 0) flag = true;
      }
      res = min(sum, res);
    } while (next_permutation(v.begin(), v.end()));

    if (flag)
      cout << -1 << "\n";
    else {
      cout << res << "\n";
    }
  }

  return 0;
}