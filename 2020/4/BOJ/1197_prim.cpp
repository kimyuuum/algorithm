
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int V = 10005;
const int E = 100005;
int vec, e, cnt;
long long res;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
               greater<pair<int, pair<int, int>>>>
    pq;
vector<pair<int, int>> edge[E];  // first : cost
bool checked[V];

void prim() {
  for (int i = 0; i < edge[1].size(); i++) {
    pq.push({edge[1][i].first, make_pair(1, edge[1][i].second)});
  }
  checked[1] = true;

  while (1) {
    int v = pq.top().second.second;
    int cost = pq.top().first;
    pq.pop();

    if (checked[v]) continue;

    checked[v] = true;
    res += (long long)cost;
    cnt++;
    for (int i = 0; i < edge[v].size(); i++) {
      int node = edge[v][i].second;
      if (!checked[node]) {
        pq.push(make_pair(edge[v][i].first, make_pair(v, edge[v][i].second)));
      }
    }
    if (cnt == vec - 1) {
      break;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> vec >> e;
  for (int i = 0; i < e; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    edge[b].push_back({c, a});
    edge[a].push_back({c, b});
  }

  prim();
  cout << res;
  return 0;
}