#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n, l;
vector<int> v;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> l;

  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    v.push_back(num);
  }

  sort(v.begin(), v.end());

  double end = v[0] - 0.5 + l;
  int cnt = 1;
  for (int i = 1; i < v.size(); i++) {
    double e = v[i] + 0.5;
    if (end >= e) {
      continue;
    } else {
      end = v[i] - 0.5 + l;
      cnt++;
    }
  }

  cout << cnt;
  return 0;
}