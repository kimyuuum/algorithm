
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 10001;
vector<int> v[MAX];
vector<int> rel[MAX];
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
    int a;
    cin >> a;
    for (int j = 0; j < a; j++) {
      int idx;
      cin >> idx;
      v[i].push_back(idx);
    }

    for (int k = 0; k < v[i].size(); k++) {
      int node = v[i][k];
      if (k != 0) {
        indegree[node]++;
      }
      if (k != v[i].size() - 1) {
        int nextnode = v[i][k + 1];
        rel[node].push_back(nextnode);
      }
    }
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
    for (int i = 0; i < rel[cur].size(); i++) {
      int next = rel[cur][i];
      indegree[next]--;
      if (indegree[next] == 0) {
        q.push(next);
      }
    }
  }

  if (res.size() != n) {
    cout << "0";
  } else {
    for (int i = 0; i < res.size(); i++) {
      cout << res[i] << "\n";
    }
  }

  return 0;
}