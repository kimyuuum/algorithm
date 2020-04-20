#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 100005;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
               greater<pair<int, pair<int, int>>>>
    pq;
vector<pair<int, int>> v[MAX];
bool checked[MAX];
int n, m;
long res;

void prim() {
  int cnt = 0;
  for (int i = 0; i < v[1].size(); i++) {
    pq.push(make_pair(v[1][i].first, make_pair(1, v[1][i].second)));
  }
  checked[1] = true;

  while (1) {
    int cost = pq.top().first;
    int node = pq.top().second.second;
    pq.pop();
    if (checked[node]) {
      continue;
    }
    checked[node] = true;
    cnt++;
    res += (long)cost;
    if (cnt == n - 1) break;

    for (int i = 0; i < v[node].size(); i++) {
      int nextcost = v[node][i].first;
      int nextnode = v[node][i].second;

      if (!checked[nextnode]) {
        pq.push(make_pair(nextcost, make_pair(node, nextnode)));
      }
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    v[a].push_back(make_pair(c, b));  // cost first
    v[b].push_back(make_pair(c, a));
  }

  prim();
  cout << res;

  return 0;
}