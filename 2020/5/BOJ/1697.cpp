#include <iostream>
#include <queue>
using namespace std;
const int MAX = 100001;
int n, k;
bool visited[MAX];

int bfs() {
  queue<pair<int, int>> q;
  q.push(make_pair(n, 0));
  visited[n] = true;

  while (!q.empty()) {
    int size = q.size();
    for (int s = 0; s < size; s++) {
      int curX = q.front().first;
      int sec = q.front().second;
      q.pop();

      if (curX == k) {
        return sec;
      }

      for (int i = 0; i < 3; i++) {
        int nextX;
        if (i == 0) {
          nextX = curX + 1;
        } else if (i == 1) {
          nextX = curX - 1;
        } else {
          nextX = curX * 2;
        }
        if (nextX < 0 || nextX > MAX) {
          continue;
        }
        if (visited[nextX]) {
          continue;
        }
        q.push(make_pair(nextX, sec + 1));
        visited[nextX] = true;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> k;

  int res = bfs();
  cout << res;
  return 0;
}