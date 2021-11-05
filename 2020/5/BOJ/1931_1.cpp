#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n;
vector<pair<int, int>> v;

bool comp(pair<int, int> p1, pair<int, int> p2) {
  if (p1.second == p2.second) {
    return p1.first < p2.first;
  }
  return p1.second < p2.second;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    v.push_back(make_pair(a, b));
  }

  sort(v.begin(), v.end(), comp);
  int cnt = 1;
  int t = v[0].second;
  for (int i = 1; i < v.size(); i++) {
    if (v[i].first >= t) {
      cnt++;
      t = v[i].second;
    }
  }
  cout << cnt;
  return 0;
}