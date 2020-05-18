
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> v;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    v.push_back(a);
  }

  sort(v.begin(), v.end());
  int res = 0;
  int wait = 0;

  for (int i = 0; i < v.size(); i++) {
    wait += v[i];
    res += wait;
  }
  cout << res;
}