#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
map<string, string> m;
vector<string> v;
int n;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  string name, status;
  while (n--) {
    cin >> name >> status;
    if (status == "enter") {
      m.insert(make_pair(name, status));
    } else if (status == "leave") {
      m.erase(name);
    }
  }

  map<string, string>::iterator iter;
  for (iter = m.begin(); iter != m.end(); iter++) {
    v.push_back(iter->first);
  }
  sort(v.rbegin(), v.rend());

  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << "\n";
  }

  return 0;
}