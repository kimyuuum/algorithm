#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<pair<int, int>> v;
vector<int> v2;

bool comp(pair<int, int> p1, pair<int, int> p2) { return p1.first > p2.first; }

int main() {
  for (int i = 1; i <= 8; i++) {
    int a;
    cin >> a;
    v.push_back(make_pair(a, i));
  }

  sort(v.begin(), v.end(), comp);
  int sum = 0;
  for (int i = 0; i < 5; i++) {
    sum += v[i].first;
    v2.push_back(v[i].second);
  }

  sort(v2.begin(), v2.end());

  cout << sum << endl;
  for (int i = 0; i < 5; i++) {
    cout << v2[i] << " ";
  }

  return 0;
}
