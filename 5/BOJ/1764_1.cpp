#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
vector<string> v;

int n, m;

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string name;
    cin >> name;
    v.push_back(name);
  }

  sort(v.begin(), v.end());
  vector<string> v2;

  for (int i = 0; i < m; i++) {
    string name;
    cin >> name;

    int left = 0;
    int right = n - 1;

    while (left <= right) {
      int mid = (left + right) / 2;
      if (v[mid].compare(name) > 0) {
        right = mid - 1;
      } else if (v[mid].compare(name) < 0) {
        left = mid + 1;
      } else if (v[mid].compare(name) == 0) {
        v2.push_back(name);
        break;
      }
    }
  }

  sort(v2.begin(), v2.end());
  cout << v2.size() << "\n";
  for (int i = 0; i < v2.size(); i++) {
    cout << v2[i] << "\n";
  }
  return 0;
}