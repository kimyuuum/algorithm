
#include <iostream>
#include <vector>
using namespace std;
vector<int> v;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      v.push_back(i);
    }
  }

  for (int i = v.size() - 1; i >= 0; i--) {
    if (n == v[i] * v[i]) {
      continue;
    }
    v.push_back(n / v[i]);
  }

  if (v.size() < k) {
    cout << "0";
  } else {
    cout << v[k - 1];
  }

  return 0;
}