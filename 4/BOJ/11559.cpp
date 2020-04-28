#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
char map[6][12];
int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, -1, 0, 1};
bool visited[6][12];
vector<pair<int, int>> puyo;
int res;

void ispuyo(int x, int y) {
  vector<pair<int, int>> v;
  queue<pair<int, int>> q;

  q.push(make_pair(x, y));
  v.push_back({x, y});
  char target = map[x][y];
  int cnt = 0;
  visited[x][y] = true;

  while (!q.empty()) {
    int curX = q.front().first;
    int curY = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int nextX = curX + dirX[i];
      int nextY = curY + dirY[i];

      if (nextX < 0 || nextX >= 6 || nextY < 0 || nextY >= 12) {
        continue;
      }
      if (visited[nextX][nextY] || map[nextX][nextY] != target) {
        continue;
      }

      visited[nextX][nextY] = true;
      q.push(make_pair(nextX, nextY));
      v.push_back(make_pair(nextX, nextY));
      cnt++;
    }
  }

  if (v.size() >= 4) {
    while (!v.empty()) {
      puyo.push_back(make_pair(v.back().first, v.back().second));
      v.pop_back();
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string input;
  for (int i = 11; i >= 0; i--) {
    cin >> input;
    for (int j = 0; j < 6; j++) {
      map[j][i] = input[j];
    }
  }

  while (1) {
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < 12; i++) {
      for (int j = 0; j < 6; j++) {
        if (map[j][i] != '.') {
          ispuyo(j, i);
        }
      }
    }
    if (puyo.empty()) {
      break;
    } else {
      while (!puyo.empty()) {
        int curX = puyo.back().first;
        int curY = puyo.back().second;
        map[curX][curY] = '.';
        puyo.pop_back();
      }
      res++;

      for (int i = 0; i < 6; i++) {
        queue<char> q;
        for (int j = 0; j < 12; j++) {
          if (map[i][j] != '.') {
            q.push(map[i][j]);
          }
        }
        if (!q.empty()) {
          int idx = 0;
          while (!q.empty()) {
            map[i][idx] = q.front();
            q.pop();
            idx++;
          }
          for (int k = idx; k < 12; k++) {
            map[i][k] = '.';
          }
        }
      }
    }
  }

  cout << res;
}