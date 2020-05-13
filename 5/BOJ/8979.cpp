#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Medal {
  int gold;
  int silver;
  int bronze;
};
vector<pair<Medal, int>> v;
int n, k;

bool comp(pair<Medal, int> p1, pair<Medal, int> p2) {
  if (p1.first.gold > p2.first.gold) {
    return true;
  } else if (p1.first.gold == p2.first.gold) {
    if (p1.first.silver > p2.first.silver) {
      return true;
    } else if (p1.first.silver == p2.first.silver) {
      if (p1.first.bronze > p2.first.bronze) {
        return true;
      } else if (p1.first.bronze == p2.first.bronze) {
        return p1.second == k;
      }
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int idx;
    Medal medal;
    cin >> idx >> medal.gold >> medal.silver >> medal.bronze;
    v.push_back(make_pair(medal, idx));
  }

  sort(v.begin(), v.end(), comp);

  int idx = 0;
  for (int i = 0; i < v.size(); i++) {
    if (v[i].second == k) {
      idx = i + 1;
      break;
    }
  }

  cout << idx;
  return 0;
}