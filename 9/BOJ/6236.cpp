//용돈 관리
#include <iostream>
#include <vector>
using namespace std;
int n, m;
int l = 0;
int r = 1000000000;
vector<int> money;

bool check(int val) {
  int out = 1;
  int total = val;
  for (int i = 0; i < money.size(); i++) {
    if (total >= money[i]) {
      total -= money[i];
    } else {
      total = val;
      total -= money[i];
      out++;
    }
    if (total < 0) {
      return false;
    }
  }

  if (out <= m) {
    return true;
  } else {
    return false;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    money.push_back(num);
  }

  while (l < r) {
    int mid = (l + r) / 2;

    if (check(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }

  cout << r;
  return 0;
}