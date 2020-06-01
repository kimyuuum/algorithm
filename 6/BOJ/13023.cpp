

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 2001;
vector<int> v[MAX];
bool visited[MAX];
int n, m;

void dfs(int idx, int depth) {
  if (depth == 5) {
    cout << 1;
    exit(0);
  }

  visited[idx] = true;
  for (int i = 0; i < v[idx].size(); i++) {
    int nidx = v[idx][i];
    if (!visited[nidx]) {
      visited[nidx] = true;
      dfs(nidx, depth + 1);
      visited[nidx] = false;
    }
  }
  visited[idx] = false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }

  for (int i = 0; i < n; i++) {
    sort(v[i].begin(), v[i].end());
  }

  for (int i = 0; i < n; i++) {
    dfs(i, 1);
  }

  cout << 0;

  return 0;
}
