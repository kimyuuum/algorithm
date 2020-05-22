#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n, m;
int res = 0;
vector<int> v;

bool dist(long long len) {
  int cnt = 1;
  int prev = v[0];
  for (int i = 1; i < v.size(); i++) {
    if (v[i] - prev >= len) {
      cnt++;
      prev = v[i];
    }
  }

  if (cnt >= m) {
    return true;
  }

  return false;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    v.push_back(num);
  }

  sort(v.begin(), v.end());
  long long left = 1;
  long long right = v[n - 1] - v[0];

  while (left <= right) {
    long long mid = (left + right) / 2;
    if (dist(mid)) {
      if (res < mid) {
        res = mid;
      }
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  cout << res;

  return 0;
}