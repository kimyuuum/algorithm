#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 51;
int n;
vector<int> a;
vector<int> b;
vector<pair<int, int>> r;

bool comp(pair<int, int> p1, pair<int, int> p2) { return p1.first > p2.first; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    a.push_back(num);
  }
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    b.push_back(num);
  }

  for (int i = 0; i < n; i++) {
    r.push_back(make_pair(b[i], i));
  }
  sort(r.begin(), r.end(), comp);
  sort(a.begin(), a.end());

  int res = 0;
  for (int i = 0; i < n; i++) {
    int idx = r[i].second;
    res += (b[idx] * a[i]);
  }
  cout << res;
  return 0;
}
