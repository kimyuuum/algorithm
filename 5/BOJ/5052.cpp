#include <algorithm>
#include <iostream>
using namespace std;
const int MAX = 100001;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int testcase;
  cin >> testcase;
  while (testcase--) {
    bool flag = false;

    int n;
    cin >> n;
    string arr[MAX];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    sort(arr, arr + n);
    for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
    }
    for (int i = 1; i < n; i++) {
      if (arr[i - 1].size() != arr[i].size()) {
        string sub = arr[i].substr(0, arr[i - 1].size());
        if (arr[i - 1] == sub) {
          flag = true;
          break;
        }
      }
    }
    if (flag) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }

  return 0;
}