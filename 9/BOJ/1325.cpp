#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 10001;
int n, m, cnt;
vector<int> v[MAX];
bool visited[MAX];
int res[MAX] = {0,};

bool comp(pair<int, int> p1, pair<int, int> p2) { return p1.first > p2.first; }

void dfs(int idx) {

  visited[idx] = true;

  for (int i = 0; i < v[idx].size(); i++) {
    int node = v[idx][i];
    if (!visited[node]) {
      cnt++;
      dfs(node);
    }
  }

}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    v[b].push_back(a);
  }

  int val = 0;

  for (int i = 1; i <= n; i++) {
    if (!v[i].empty()) {
      memset(visited, false, sizeof(visited));
      cnt = 1;
      dfs(i);
      res[i] = cnt;
      if (val < cnt) {
        val = cnt;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    if (val == res[i]) {
      cout << i<<" ";
    }
  }

  return 0;
}