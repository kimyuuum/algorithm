#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 200004;
bool check[MAX];
int m, n;
long long entire, res;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  while (1) {
    entire = 0, res = 0;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>>
        pq;
    vector<pair<int, int>> v[MAX];
    memset(check, false, sizeof(check));
    cin >> m >> n;
    if (m == 0 && n == 0) break;
    for (int i = 0; i < n; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      v[a].push_back(make_pair(c, b));
      v[b].push_back(make_pair(c, a));
      entire += c;
    }
    int cnt = 0;
    for (int i = 0; i < v[0].size(); i++) {
      pq.push(make_pair(v[0][i].first, make_pair(0, v[0][i].second)));
    }

    check[0] = true;

    while (1) {
      int cost = pq.top().first;
      int u = pq.top().second.second;
      pq.pop();

      if (check[u]) continue;
      check[u] = true;
      cnt++;
      res += (long long)cost;
      if (cnt == m - 1) break;
      for (int i = 0; i < v[u].size(); i++) {
        if (!check[v[u][i].second]) {
          pq.push(make_pair(v[u][i].first, make_pair(u, v[u][i].second)));
        }
      }
    }
    cout << entire - res << "\n";
  }
  return 0;
}
