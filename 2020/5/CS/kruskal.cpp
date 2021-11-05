#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int V = 1001;
const int E = 100001;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
               greater<pair<int, pair<int, int>>>>
    pq;
int n, m, res;
int root[V];

int find(int x) {
  if (root[x] == x) {
    return x;
  }

  int parent = root[x];
  return root[x] = find(parent);
}

void uni(int x, int y) {
  x = find(x);
  y = find(y);

  root[y] = x;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;

  for (int i = 1; i < V; i++) {
    root[i] = i;
  }

  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    pq.push(make_pair(c, make_pair(a, b)));
  }

  while (!pq.empty()) {
    int x = find(pq.top().second.first);
    int y = find(pq.top().second.second);
    int cost = pq.top().first;
    pq.pop();

    if (x == y) {
      continue;
    }

    res += cost;
    uni(x, y);
  }

  cout << res;
  return 0;
}