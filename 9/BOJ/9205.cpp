
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 33000;
int t, n;
int sx, sy, fx, fy;
vector<pair<pair<int, int>, int>> store;
bool visited[MAX] = {
    false,
};
bool res = false;

void dfs(int x, int y, int idx) {
  if (x == fx && y == fy) {
    res = true;
    return;
  }

  visited[idx] = true;

  for (int i = 0; i < store.size(); i++) {
    int nx = store[i].first.first;
    int ny = store[i].first.second;
    int nidx = store[i].second;

    int dir = abs(nx - x) + abs(ny - y);

    if (!visited[nidx] && dir <= 1000) {
      dfs(nx, ny, nidx);
    }
  }

  return;
}

int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    store = {};
    res = false;
    memset(visited,false,sizeof(visited));
    for (int i = 0; i < n + 2; i++) {
      int x, y;
      cin >> x >> y;
      if (i == 0) {
        sx = x;
        sy = y;
      } else if (i == n + 1) {
        fx = x;
        fy = y;
      }
      store.push_back({{x, y}, i});
    }
    dfs(sx, sy, 0);
    if (res) {
      cout << "happy\n";
    } else {
      cout << "sad\n";
    }
  }

  return 0;
}