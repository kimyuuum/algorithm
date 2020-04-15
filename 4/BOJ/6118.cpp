#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 20002;
const int INF = 987654321;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<int> v[MAX];
int dist[MAX];
int n, m;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int a, b;

  cin >> n >> m;

  while (m--) {
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }

  for (int i = 2; i <= n; i++) {
    dist[i] = INF;
  }

  pq.push(make_pair(1, 0));
  while (!pq.empty()) {
    int node = pq.top().first;
    int cost = pq.top().second;
    pq.pop();

    for (int i = 0; i < v[node].size(); i++) {
      int nextNode = v[node][i];
      int nextCost = cost + 1;

      if (dist[nextNode] > nextCost) {
        dist[nextNode] = nextCost;
        pq.push(make_pair(nextNode, nextCost));
      }
    }
  }

  int max = 0, cnt = 0, idx;

  for (int i = 2; i <= n; i++) {
    if (dist[i] > max) {
      cnt = 1;
      max = dist[i];
      idx = i;
    } else if (dist[i] == max) {
      cnt++;
    }
  }

  cout << idx << " " << max << " " << cnt;
  return 0;
}

