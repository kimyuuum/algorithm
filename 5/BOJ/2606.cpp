#include <iostream>
#include <vector>
using namespace std;
const int MAX = 101;
bool visited[MAX];
vector<int> v[MAX];
int n, m;

void dfs(int idx) {
  visited[idx] = true;

  for (int i = 0; i < v[idx].size(); i++) {
    int node = v[idx][i];
    if (!visited[node]) {
      dfs(node);
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }

  dfs(1);
  int cnt = 0;

  for (int i = 2; i <= n; i++) {
    if (visited[i]) {
      cnt++;
    }
  }
  cout << cnt;
  return 0;
}