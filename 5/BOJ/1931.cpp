#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100001;
vector<pair<int, int>> v;
int n;

bool comp(pair<int, int> v1, pair<int, int> v2) {
  if (v1.second == v2.second) {
    return v1.first < v2.first;
  }

  return v1.second < v2.second;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    v.push_back(make_pair(a, b));
  }

  sort(v.begin(), v.end(), comp);

  int end = v[0].second;

  int cnt = 1;

  for (int i = 1; i < n; i++) {
    if (v[i].first >= end) {
      cnt++;
      end = v[i].second;
    }
  }

  cout << cnt;
  return 0;
}