#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1001;
vector<pair<int, int>> v;
int p[MAX];
int a[MAX];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    v.push_back(make_pair(a[i], i));
  }

  sort(v.begin(), v.end());

  for (int i = 0; i < v.size(); i++) {
    p[v[i].second] = i;
  }

  for (int i = 0; i < n; i++) {
    cout << p[i] << " ";
  }
  return 0;
}

// b[p[2]] = 1 b[p[0]] = 2 b[p[1]] = 3
// p[0] = 1 p[1] = 2 p[2] = 0
