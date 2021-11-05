//이분 그래프
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 20002;
int node[MAX] = {
    0,
};
vector<int> v[MAX];
bool isBipartite = true;

void dfs(int n, int parent) {

  if (node[parent] == 1) {
    node[n] = 2;
  } else {
    node[n] = 1;
  }

  for (int i = 0; i < v[n].size(); i++) {
    int nextNode = v[n][i];
    if (node[nextNode] == 0) {
      dfs(nextNode, n);
    } else {
      if (node[nextNode] == node[n]) {
        isBipartite = false;
        return;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int testcase;
  cin >> testcase;

  while (testcase--) {
    int vertex, edge;
    memset(node, 0, sizeof(node));
    isBipartite = true;
    for (int i = 0; i < MAX; i++) {
      v[i].clear();
    }

    cin >> vertex >> edge;

    for (int i = 0; i < edge; i++) {
      int a, b;
      cin >> a >> b;
      v[a].push_back(b);
      v[b].push_back(a);
    }

    for (int i = 1; i <= vertex; i++) {
      if (node[i] == 0) {
        node[i] = 1;
        for (int j = 0; j < v[i].size(); j++) {
          int nextNode = v[i][j];
          dfs(nextNode, i);
        }
      }
      if (!isBipartite) {
        break;
      }
    }
    if (isBipartite) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}