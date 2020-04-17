
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 320003;
vector<int> v[MAX];
vector<int> res;
queue<int> q;
int indegree[MAX];
int n, m;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    v[a].push_back(b);
    indegree[b]++;
  }

  for (int i = 1; i <= n; i++) {
    if (indegree[i] == 0) {
      q.push(i);
    }
  }

  while (!q.empty()) {
    int cur = q.front();
    res.push_back(cur);
    q.pop();

    for (int i = 0; i < v[cur].size(); i++) {
      int node = v[cur][i];
      indegree[node]--;
      if (indegree[node] == 0) {
        q.push(node);
      }
    }
  }

  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }

  return 0;
}