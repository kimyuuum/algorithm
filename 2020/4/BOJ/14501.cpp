#include <iostream>
#include <vector>
using namespace std;
const int MAX = 16;
bool visited[MAX];
vector<pair<int, int>> v[MAX];
int res, cost, n;

void dfs(int day) {
  visited[day] = true;
  int endDate = v[day].front().first;
  int price = v[day].front().second;

  if (endDate == n) {
    cost += price;
    cout << day << " " << cost << "\n";
    if (cost > res) {
      res = cost;
    }
    return;
  }

  cost += price;

  for (int i = day + 1; i <= n; i++) {
    int nextDate = i;
    int nextEndDate = v[i].front().first;
    int nextPrice = v[i].front().second;
    if (visited[nextDate] || nextDate <= endDate || nextEndDate > n) {
      continue;
    }
    visited[nextDate] = true;
    dfs(nextDate);
    visited[nextDate] = false;
    cost -= nextPrice;
  }

  cout << day << " " << cost << "\n";
  if (cost > res) {
    res = cost;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int a, b;
    cin >> a >> b;
    v[i].push_back({i + a - 1, b});
  }

  for (int i = 1; i <= n; i++) {
    cost = 0;
    if (v[i].front().first <= n) dfs(i);
  }
  cout << res;
  return 0;
}