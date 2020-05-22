#include <iostream>
#include <list>
#include <vector>
using namespace std;
int n, k;
list<int> l;
vector<int> ans;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;

  for (int i = 1; i <= n; i++) {
    l.push_back(i);
  }

  int cnt = 0;
  list<int>::iterator it = l.begin();

  while (!l.empty()) {
    for (int i = 0; i < k - 1; i++) {
      it++;
      if (it == l.end()) {
        it = l.begin();
      }
    }

    ans.push_back(*it);
    it = l.erase(it);

    if (it == l.end()) {
      it = l.begin();
    }
  }

  cout << "<";
  for (int i = 0; i < ans.size() - 1; i++) {
    cout << ans[i] << ", ";
  }
  cout << ans[ans.size() - 1] << ">";

  return 0;
}
