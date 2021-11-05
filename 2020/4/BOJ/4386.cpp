
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 10005;
pair<double, pair<int, int>> edge[MAX];
vector<pair<double, double>> v;
int root[MAX];
int n, idx;
double res;

int find(int x) {
  if (root[x] == x)
    return x;
  else {
    int parent = root[x];
    return root[x] = find(parent);
  }
}

bool isUnion(int x, int y) {
  x = find(x);
  y = find(y);

  if (x == y)
    return false;
  else {
    root[y] = x;
    return true;
  }
}

void kruskal() {
  int cnt = 0;

  for (int i = 0; i < idx; i++) {
    root[i] = i;
  }

  for (int i = 0; i < idx; i++) {
    double cost = edge[i].first;
    int u = edge[i].second.first;
    int v = edge[i].second.second;

    if (!isUnion(u, v)) {
      continue;
    }
    cnt++;
    res += cost;
    if (cnt == n - 1) break;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;

  for (int i = 0; i < n; i++) {
    double a, b;
    cin >> a >> b;
    v.push_back(make_pair(a, b));
  }

  for (int i = 0; i < n; i++) {
    double ux = v[i].first;
    double uy = v[i].second;
    for (int j = i + 1; j < n; j++) {
      double vx = v[j].first;
      double vy = v[j].second;

      double val = sqrt(pow(abs(vx - ux), 2) + pow(abs(vy - uy), 2));
      edge[idx].first = val;
      edge[idx].second = make_pair(i, j);
      idx++;
    }
  }

  sort(edge, edge + idx);

  kruskal();

  printf("%.2lf", res);
  return 0;
}