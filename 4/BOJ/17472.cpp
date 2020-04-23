#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 11;
const int M = 7;
const int E = 10000;
int map[MAX][MAX];
int n, m, idx, vsize, res, cnt;
int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};
int root[M];
bool vis[MAX][MAX];
queue<pair<int, int>> island;
vector<pair<int, int>> v[M];
pair<int, pair<int, int>> edge[E];

void makeIsland() {
  queue<pair<int, int>> q;

  int num = 1;
  while (!island.empty()) {
    int curX = island.front().first;
    int curY = island.front().second;
    island.pop();
    if (vis[curX][curY]) {
      continue;
    }
    vis[curX][curY] = true;
    map[curX][curY] = num;
    v[num].push_back(make_pair(curX, curY));
    for (int i = 0; i < 4; i++) {
      int nextX = curX + dirX[i];
      int nextY = curY + dirY[i];

      if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n) {
        continue;
      }
      if (vis[nextX][nextY]) continue;
      if (map[nextX][nextY] == 1) {
        map[nextX][nextY] = num;
        v[num].push_back(make_pair(nextX, nextY));
        q.push(make_pair(nextX, nextY));
        vis[nextX][nextY] = true;
      }
    }

    while (!q.empty()) {
      int x = q.front().first;
      int y = q.front().second;
      q.pop();

      for (int i = 0; i < 4; i++) {
        int nextX = x + dirX[i];
        int nextY = y + dirY[i];
        if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n) {
          continue;
        }
        if (vis[nextX][nextY]) continue;
        if (map[nextX][nextY] == 1) {
          map[nextX][nextY] = num;
          v[num].push_back(make_pair(nextX, nextY));
          q.push(make_pair(nextX, nextY));
          vis[nextX][nextY] = true;
        }
      }
    }
    num++;
  }

  vsize = num;
}

void checkX(int startX, int startY) {
  for (int i = 0; i < 4; i++) {
    int nextX = startX + dirX[i];
    int nextY = startY + dirY[i];
    int len = 0;
    while (1) {
      if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n) {
        break;
      }
      if (map[nextX][nextY] != 0) {
        break;
      }
      nextX += dirX[i];
      nextY += dirY[i];
      len++;
    }
    if (nextX >= 0 && nextX < m && nextY >= 0 && nextY < n) {
      if (len >= 2) {
        edge[idx].first = len;
        edge[idx].second.first = map[startX][startY];
        edge[idx].second.second = map[nextX][nextY];
        idx++;
      }
    }
  }
}

void makeEdge() {
  for (int i = 1; i < vsize; i++) {
    for (int j = 0; j < v[i].size(); j++) {
      int startX = v[i][j].first;
      int startY = v[i][j].second;
      checkX(startX, startY);
    }
  }
}

int find(int x) {
  if (root[x] == x)
    return x;
  else {
    int parent = root[x];
    return root[x] = find(parent);
  }
}

void kruskal() {
  for (int i = 0; i < idx; i++) {
    int a = edge[i].second.first;
    int b = edge[i].second.second;
    int val = edge[i].first;

    int x = find(a);
    int y = find(b);
    if (x != y) {
      root[y] = x;
      res += val;
      cnt++;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> map[j][i];
      if (map[j][i] == 1) {
        island.push(make_pair(j, i));
      }
    }
  }
  makeIsland();
  makeEdge();
  sort(edge, edge + idx);

  for (int i = 1; i < vsize; i++) {
    root[i] = i;
  }

  kruskal();
  if (res == 0 || cnt != vsize - 2)
    cout << -1;
  else
    cout << res;
  return 0;
}