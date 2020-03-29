
#include <iostream>
#include <queue>
using namespace std;
const int MAX = 500001;
bool visited[2][MAX];
int n, k;

int bfs() {
  queue<int> q;
  q.push(n);
  visited[0][n] = true;
  int curK = k;
  int sec = 1;
  if (n == k) return 0;
  while (!q.empty()) {
    curK += sec;
    if (curK >= MAX) return -1;
    if (visited[sec % 2][curK]) {
      return sec;
    }
    int size = q.size();
    for (int s = 0; s < size; s++) {
      int curX = q.front();
      q.pop();
      if (curX + 1 == curK || curX - 1 == curK || curX * 2 == curK) {
        return sec;
      } else {
        if (curX + 1 < MAX && !visited[sec % 2][curX + 1]) {
          q.push(curX + 1);
          visited[sec % 2][curX + 1] = true;
        }
        if (curX - 1 >= 0 && !visited[sec % 2][curX - 1]) {
          q.push(curX - 1);
          visited[sec % 2][curX - 1] = true;
        }
        if (curX * 2 < MAX && !visited[sec % 2][curX * 2]) {
          q.push(curX * 2);
          visited[sec % 2][curX * 2] = true;
        }
      }
    }
    sec++;
  }
  return -1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> k;

  int res = bfs();
  cout << res;

  return 0;
}