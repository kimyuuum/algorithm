#include <iostream>
#include <set>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int testcase;
  cin >> testcase;
  while (testcase--) {
    int n;
    cin >> n;
    multiset<int> s;

    for (int i = 0; i < n; i++) {
      char command;
      int num;
      cin >> command >> num;

      if (command == 'I') {
        s.insert(num);
      } else if (command == 'D') {
        if (!s.empty()) {
          if (num == 1) {
            s.erase(--s.end());
          } else if (num == -1) {
            s.erase(s.begin());
          }
        }
      }
    }

    if (!s.empty()) {
      cout << *(--s.end()) << " " << *s.begin() << "\n";
    } else {
      cout << "EMPTY\n";
    }
  }
  return 0;
}