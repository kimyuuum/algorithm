#include <iostream>
#include <queue>
using namespace std;
const int MAX = 2001;
int map[MAX][MAX] = {
    0,
};
int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {-1, 0, 1, 0};
bool visited[MAX][MAX] = {
    false,
};
int res = 0, N, M;
queue<pair<pair<int, int>, int> > q;

void makeWind() {
  while (!q.empty()) {
    int curX = q.front().first.first;
    int curY = q.front().first.second;
    int wind = q.front().second;
    q.pop();

    int nextX = 0;
    int nextY = 0;

    switch (wind) {
      case 1:
        nextX = curX;
        nextY = curY - 1;
        break;
      case 2:
        nextX = curX + 1;
        nextY = curY;
        break;
      case 3:
        nextX = curX;
        nextY = curY + 1;
        break;
      case 4:
        nextX = curX - 1;
        nextY = curY;
        break;
    }

    if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N) {
      continue;
    }

    if (visited[nextX][nextY] != true) {
      res++;
      visited[nextX][nextY] = true;
    }

    if (map[nextX][nextY] == 0) {
      q.push(make_pair(make_pair(nextX, nextY), wind));
    } else if (map[nextX][nextY] == 1) {
      if (wind == 1 || wind == 3) {
        q.push(make_pair(make_pair(nextX, nextY), wind));
      }
    } else if (map[nextX][nextY] == 2) {
      if (wind == 2 || wind == 4) {
        q.push(make_pair(make_pair(nextX, nextY), wind));
      }
    } else if (map[nextX][nextY] == 3) {
      if (wind == 1) {
        q.push(make_pair(make_pair(nextX, nextY), 2));
      } else if (wind == 2) {
        q.push(make_pair(make_pair(nextX, nextY), 1));
      } else if (wind == 3) {
        q.push(make_pair(make_pair(nextX, nextY), 4));
      } else {
        q.push(make_pair(make_pair(nextX, nextY), 3));
      }
    } else if (map[nextX][nextY] == 4) {
      if (wind == 1) {
        q.push(make_pair(make_pair(nextX, nextY), 4));
      } else if (wind == 2) {
        q.push(make_pair(make_pair(nextX, nextY), 3));
      } else if (wind == 3) {
        q.push(make_pair(make_pair(nextX, nextY), 2));
      } else {
        q.push(make_pair(make_pair(nextX, nextY), 1));
      }
    }
  }
}

int main() {
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> map[j][i];
      if (map[j][i] == 9) {
        visited[j][i] = true;
        res++;
        q.push(make_pair(make_pair(j, i), 1));
        q.push(make_pair(make_pair(j, i), 2));
        q.push(make_pair(make_pair(j, i), 3));
        q.push(make_pair(make_pair(j, i), 4));
      }
    }
  }
  makeWind();
  cout << res;

  return 0;
}
