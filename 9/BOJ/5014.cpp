
#include <iostream>
#include <queue>
using namespace std;
const int MAX = 1000001;
bool visited[2][MAX] = {
    false,
};
int f, g, s, u, d;
int res = 987654321;

void bfs() {
  queue<pair<int, int>> q;

  q.push(make_pair(s, 0));

  while (!q.empty()) {
    int floor = q.front().first;
    int cnt = q.front().second;

    q.pop();

    if (floor == g) {
      if (res > cnt) {
        res = cnt;
      }
      continue;
    }

    int nfloor = floor + u;
    if (nfloor <= f && !visited[0][nfloor]) {
      q.push(make_pair(nfloor, cnt + 1));
      visited[0][nfloor] = true;
    }

    nfloor = floor - d;
    if (nfloor > 0 && !visited[1][nfloor]) {
      q.push(make_pair(nfloor, cnt + 1));
      visited[1][nfloor] = true;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> f >> s >> g >> u >> d;

  bfs();

  if (res == 987654321) {
    cout << "use the stairs\n";
  } else {
    cout << res;
  }

  return 0;
}