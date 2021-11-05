#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 1001;
vector<int> v[MAX];
bool visited[MAX];
int n, m, a;

void dfs(int idx) {
  cout << idx << " ";
  visited[idx] = true;

  for (int i = 0; i < v[idx].size(); i++) {
    int node = v[idx][i];
    if (!visited[node]) {
      dfs(node);
    }
  }
}

void bfs(int idx) {
  visited[idx] = true;
  queue<int> q;
  q.push(idx);
  while (!q.empty()) {
    int cur = q.front();
    cout << cur << " ";
    q.pop();

    for (int i = 0; i < v[cur].size(); i++) {
      int node = v[cur][i];
      if (!visited[node]) {
        q.push(node);
        visited[node] = true;
      }
    }
  }
  cout << endl;
}
int main() {
  cin >> n >> m >> a;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }

  for (int i = 0; i < n; i++) {
    sort(v[i].begin(), v[i].end());
  }

  dfs(a);
  cout << endl;
  memset(visited, false, sizeof(visited));
  bfs(a);

  return 0;
}