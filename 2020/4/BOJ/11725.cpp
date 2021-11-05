#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 100001;
int res[MAX];
int n;
bool visited[MAX];
vector<int> v[MAX];

void dfs(int cur) {
  for (int i = 0; i < v[cur].size(); i++) {
    int next = v[cur][i];
    if (!visited[next]) {
      visited[next] = true;
      res[next] = cur;
      dfs(next);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  visited[1] = true;
  dfs(1);

  for (int i = 2; i <= n; i++) {
    cout << res[i] << " ";
  }
}