#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int V = 10001;
const int E = 100001;
int v, e;
bool isconnect[V];
vector<pair<int, int>> adj[V];
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
               greater<pair<int, pair<int, int>>>>
    pq;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int res = 0;
  cin >> v >> e;
  for (int i = 0; i < e; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back(make_pair(b, c));
    adj[b].push_back(make_pair(a, c));
  }

  for (int i = 0; i < adj[1].size(); i++) {
    pq.push(make_pair(adj[1][i].second, make_pair(1, adj[1][i].first)));
  }

  isconnect[1] = true;
  int cnt = 1;

  while (!pq.empty()) {
    int val = pq.top().first;
    int node = pq.top().second.second;
    pq.pop();

    if (isconnect[node]) {
      continue;
    }

    res += val;
    cnt++;
    isconnect[node] = true;

    if (cnt == v - 1) {
      break;
    }

    for (int i = 0; i < adj[node].size(); i++) {
      int nextval = adj[node][i].second;
      int nextnode = adj[node][i].first;

      if (!isconnect[nextnode]) {
        pq.push(make_pair(nextval, make_pair(node, nextnode)));
      }
    }
  }

  cout << res;
  return 0;
}
