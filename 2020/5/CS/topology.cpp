#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int V = 32001;
vector<int> adj[V];
queue<int> q;
vector<int> res;
int indegree[V];
int n, m;

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    indegree[b]++;
  }

  for (int i = 1; i <= n; i++) {
    if (indegree[i] == 0) {
      q.push(i);
    }
  }

  while (!q.empty()) {
    int node = q.front();
    res.push_back(node);
    q.pop();

    for (int i = 0; i < adj[node].size(); i++) {
      int nextnode = adj[node][i];
      indegree[nextnode]--;
      if (indegree[nextnode] == 0) {
        q.push(nextnode);
      }
    }
  }

  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }

  return 0;
}