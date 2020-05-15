#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> v;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    v.push_back(num);
  }

  sort(v.begin(), v.end());

  int res = 0;
  do {
    int cnt = 0;
    for (int i = 0; i < v.size() - 1; i++) {
      cnt += abs(v[i] - v[i + 1]);
    }
    if (cnt > res) {
      res = cnt;
    }

  } while (next_permutation(v.begin(), v.end()));

  cout << res;
  return 0;
}