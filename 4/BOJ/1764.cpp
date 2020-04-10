
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 500000;
vector<string> v;
vector<string> res;
int n, m, l, r;

bool binarySearch(int l, int r, string target) {
  if (l > r) {
    return false;
  }

  int mid = (l + r) / 2;
  if (!v[mid].compare(target)) {
    return true;
  } else if (v[mid].compare(target) > 0) {
    return binarySearch(l, mid - 1, target);
  } else {
    return binarySearch(mid + 1, r, target);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string input;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> input;
    v.push_back(input);
  }

  sort(v.begin(), v.end());

  while (m--) {
    cin >> input;
    l = 0;
    r = v.size() - 1;
    if (binarySearch(l, r, input)) {
      res.push_back(input);
    }
  }

  sort(res.begin(), res.end());
  cout << res.size() << "\n";
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << "\n";
  }
  return 0;
}