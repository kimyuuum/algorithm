
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 501;
vector<int> v[MAX];
bool visited[MAX];
int n, m, res;

void dfs(int cur, int depth) {
  if (depth > 2) {
    return;
  }

  visited[cur] = true;

  for (int i = 0; i < v[cur].size(); i++) {
    int next = v[cur][i];
    if (cur == 1) {
      dfs(next, depth + 1);
    } else if (!visited[next]) {
      dfs(next, depth + 1);
    }
  }

}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int a, b;
  cin >> n >> m;
  while (m--) {
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }

  dfs(1, 0);

  int cnt = 0;

  for (int i = 2; i <= n; i++) {
    if (visited[i]) {
      cnt++;
    }
  }

  cout << cnt;
  return 0;
}