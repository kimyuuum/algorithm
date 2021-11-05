#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  while (1) {
    vector<int> v;
    int n;
    cin >> n;
    if (n == 0)
      break;
    else {
      for (int i = 0; i < n; i++) {
        int s;
        cin >> s;
        v.push_back(s);
      }

      vector<int> v2;

      for (int i = 0; i < 6; i++) {
        v2.push_back(0);
      }
      for (int i = 0; i < v.size() - 6; i++) {
        v2.push_back(1);
      }

      do {
        for (int i = 0; i < v2.size(); i++) {
          if (v2[i] == 0) {
            cout << v[i] << " ";
          }
        }
        cout << endl;
      } while (next_permutation(v2.begin(), v2.end()));
    }

    cout << endl;
  }

  return 0;
}
