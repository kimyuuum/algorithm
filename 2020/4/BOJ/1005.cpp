#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 1001;
int delay[MAX];
int construct[MAX];
int indegree[MAX];
int res, n, k, target;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int testcase;
  cin >> testcase;
  while (testcase--) {
    vector<int> v[MAX];
    queue<pair<int, int>> q;
    memset(delay, 0, sizeof(delay));
    memset(construct, 0, sizeof(construct));
    memset(indegree, 0, sizeof(indegree));
    res = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      cin >> delay[i];
    }
    for (int i = 1; i <= k; i++) {
      int a, b;
      cin >> a >> b;
      v[a].push_back(b);
      indegree[b]++;
    }
    cin >> target;
    if (indegree[target] == 0) {
      cout << delay[target] << "\n";
      continue;
    }
    for (int i = 1; i <= n; i++) {
      if (indegree[i] == 0) {
        q.push({i, 1});
        construct[i] = delay[i];
      }
    }
    while (!q.empty()) {
      int cur = q.front().first;
      int lev = q.front().second;

      if (cur == target) {
        break;
      }
      q.pop();

      for (int i = 0; i < v[cur].size(); i++) {
        int next = v[cur][i];
        int nextlev = lev + 1;
        if (construct[next] < delay[next] + construct[cur]) {
          construct[next] = delay[next] + construct[cur];
        }
        if (next != target && v[next].size() == 0) {
          continue;
        }
        indegree[next]--;
        if (indegree[next] == 0) {
          q.push(make_pair(next, nextlev));
        }
      }
    }

    cout << construct[target] << "\n";
  }

  return 0;
}
