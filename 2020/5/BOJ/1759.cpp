#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<char> v;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int l, c;
  cin >> l >> c;
  for (int i = 0; i < c; i++) {
    char input;
    cin >> input;
    v.push_back(input);
  }

  sort(v.begin(), v.end());

  vector<int> v2;
  for (int i = 0; i < l; i++) {
    v2.push_back(0);
  }
  for (int i = 0; i < c - l; i++) {
    v2.push_back(1);
  }

  do {
    int c = 0, vl = 0;
    for (int i = 0; i < v2.size(); i++) {
      if (v2[i] == 0) {
        if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' ||
            v[i] == 'u') {
          c++;
        } else {
          vl++;
        }
      }
    }
    if (c >= 1 && vl >= 2) {
      for (int i = 0; i < v2.size(); i++) {
        if (v2[i] == 0) {
          cout << v[i];
        }
      }
      cout << endl;
    }

  } while (next_permutation(v2.begin(), v2.end()));
  return 0;
}