
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1001;
vector<int> v[MAX];
bool visited[MAX];
int n, m;

void dfs(int idx) {
  visited[idx] = true;
  for (int i = 0; i < v[idx].size(); i++) {
    int num = v[idx][i];
    if (!visited[num]) {
      dfs(num);
    }
  }
}
int main() {
  cin >> n >> m;
  int a, b;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  int res = 0;
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      dfs(i);
      res++;
    }
  }

  cout << res;

  return 0;
}