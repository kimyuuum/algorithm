#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int testcase;
  cin >> testcase;
  while (testcase--) {
    int num;
    vector<pair<int, int>> v;
    cin >> num;
    for (int i = 0; i < num; i++) {
      int a, b;
      cin >> a >> b;
      v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end());
    int cnt = 1;
    int mnum = v[0].second;
    for (int i = 1; i < v.size(); i++) {
      if (v[i].second < mnum) {
        cnt++;
        mnum = v[i].second;
      }
    }
    cout << cnt << "\n";
  }
  return 0;
}