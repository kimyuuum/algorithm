
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int V = 20002;
const int E = 300003;
const int INF = 987654321;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    pq;
vector<pair<int, int>> v[E];
int dist[V];
bool visited[V];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int vertex, edge, k;
  cin >> vertex >> edge >> k;

  for (int i = 1; i <= V; i++) {
    if (i == k) {
      dist[i] = 0;
    } else {
      dist[i] = INF;
    }
  }

  for (int i = 0; i < edge; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    v[a].push_back(make_pair(b, c));
  }

  pq.push(make_pair(0, k));

  while (!pq.empty()) {
    int node = pq.top().second;
    int cost = pq.top().first;
    pq.pop();

    if (dist[node] < cost) {
      continue;
    }

    for (int i = 0; i < v[node].size(); i++) {
      int nextnode = v[node][i].first;
      int nextcost = cost + v[node][i].second;
      if (nextcost < dist[nextnode]) {
        pq.push(make_pair(nextcost, nextnode));
        dist[nextnode] = nextcost;
      }
    }
  }

  for (int i = 1; i <= vertex; i++) {
    if (dist[i] == INF) {
      cout << "INF\n";
    } else {
      cout << dist[i] << "\n";
    }
  }

  return 0;
}