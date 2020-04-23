#include <iostream>
#include <queue>
using namespace std;
const int MAX = 105;
int map[MAX][MAX];
bool snake[MAX][MAX];
int n, k, l, sec = 1;
vector<char> v[MAX * MAX];
int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};

int dummy() {
  queue<pair<int, int>> q;

  int dir = 0;
  q.push(make_pair(1, 1));

  while (1) {
    int curX = q.back().first;
    int curY = q.back().second;

    int nextX = curX + dirX[dir];
    int nextY = curY + dirY[dir];
    q.push(make_pair(nextX, nextY));

    if (snake[nextX][nextY]) {
      return sec;
    } else if (nextX < 1 || nextX > n || nextY < 1 || nextY > n) {
      return sec;
    }

    if (map[nextX][nextY]) {
      snake[nextX][nextY] = true;
      map[nextX][nextY] = 0;
    } else {
      int x = q.front().first;
      int y = q.front().second;
      q.pop();
      snake[x][y] = false;
      snake[nextX][nextY] = true;
    }

    if (!v[sec].empty()) {
      char command = v[sec].back();
      if (command == 'L') {
        if (dir == 0)
          dir = 3;
        else
          dir--;
      } else if (command == 'D') {
        if (dir == 3)
          dir = 0;
        else
          dir++;
      }
    }
    curX = nextX;
    curY = nextY;
    sec++;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;
  snake[1][1] = true;

  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    map[b][a] = 1;
  }

  cin >> l;
  for (int i = 0; i < l; i++) {
    int a;
    char com;
    cin >> a >> com;
    v[a].push_back(com);
  }

  cout << dummy();

  return 0;
}