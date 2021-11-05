#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> v;

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    v.push_back(num);
  }

  sort(v.begin(), v.end());

  vector<int> v2;
  for (int i = 0; i < 3; i++) {
    v2.push_back(0);
  }

  for (int i = 0; i < n - 3; i++) {
    v2.push_back(1);
  }
  int res = 0;
  do {
    int sum = 0;
    for (int i = 0; i < v2.size(); i++) {
      if (v2[i] == 0) {
        sum += v[i];
      }
    }

    if (sum <= m) {
      if (m - sum < m - res) {
        res = sum;
      }
    }

  } while (next_permutation(v2.begin(), v2.end()));
  cout << res;
  return 0;
}