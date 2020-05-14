#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1001;
vector<int> v[MAX];
bool visited[MAX];
int n, m;
int cnt = 0;
void dfs(int idx) {
  visited[idx] = true;
  for (int i = 0; i < v[idx].size(); i++) {
    int next = v[idx][i];
    if (!visited[next]) {
      dfs(next);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }

  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      dfs(i);
      cnt++;
    }
  }

  cout << cnt;
  return 0;
}