//탑
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack<pair<int, int>> s;
vector<int> v;
int n, cnt = 1;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n;

  while (n--) {
    int num;
    cin >> num;

    if (s.empty()) {
      s.push({num, 1});
      v.push_back(0);
    } else {
      if (s.top().first > num) {
        v.push_back(s.top().second);
        s.push({num, cnt});
      } else if (s.top().first < num) {
        while (!s.empty() && (s.top().first < num)) {
          s.pop();
        }
        if (s.empty()) {
          v.push_back(0);
        } else {
          v.push_back(s.top().second);
        }
        s.push({num, cnt});
      }
    }
    cnt++;
  }

  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }

  return 0;
}