#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 10005;
const int E = 100005;
int vec, e;
long long kres, pres;
int cnt;
pair<int, pair<int, int>> edge[E];
int root[MAX];

int find(int x) {
  if (root[x] == x)
    return x;
  else {
    int parent = root[x];
    return root[x] = find(parent);
  }
}

bool unionfind(int u, int v) {
  u = find(u);
  v = find(v);

  if (u == v) {
    return false;
  } else {
    root[v] = u;
  }
  return true;
}

void kruskal() {
  for (int i = 0; i < e; i++) {
    int cost = edge[i].first;
    int u = edge[i].second.first;
    int v = edge[i].second.second;

    if (!unionfind(u, v)) {  // 같은 그룹일 경우
      continue;
    }
    kres += (long long)cost;
    cnt++;
    if (cnt == vec - 1) break;
  }
}

void prim() {}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> vec >> e;
  for (int i = 1; i <= vec; i++) {
    root[i] = i;
  }
  for (int i = 0; i < e; i++) {
    cin >> edge[i].second.first >> edge[i].second.second >> edge[i].first;
  }

  sort(edge, edge + e);
  kruskal();
  cout << kres;
  return 0;
}