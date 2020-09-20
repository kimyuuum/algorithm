#include <iostream>
#include <vector>
using namespace std;
const int MAX = 105;
vector<int> v[MAX];
int n, m, a, b;
bool visited[MAX][MAX];
bool related = false;
int res = 987654321;

void dfs(int x, int y, int cnt) {

  if (y == b) {
    if (cnt < res) {
      res = cnt;
    }
    related = true;
    return;
  }

  for (int i = 0; i < v[y].size(); i++) {
    if (v[y][i] != x) {
      dfs(y, v[y][i], cnt + 1);
    }
  }

  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> a >> b;
  cin >> m;

  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }

  for (int i = 0; i < v[a].size(); i++) {
    dfs(a, v[a][i], 1);
  }

  if (a == b) {
    cout << 0;
  } else if (!related) {
    cout << -1;
  } else {
    cout << res;
  }
  return 0;
}