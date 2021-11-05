
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int main() {
  string a, b;
  bool flag = false;
  cin >> a >> b;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int aIdx = 0, bIdx = 0;
  while (aIdx < a.size() && bIdx < b.size()) {
    if (a[aIdx] == b[bIdx]) {
      flag = true;
      break;
    } else {
      if (a[aIdx] < b[bIdx]) {
        aIdx++;
      } else if (a[aIdx] > b[bIdx]) {
        bIdx++;
      }
    }
  }

  if (flag) {
    cout << "duplicate";
  } else {
    cout << "not duplicate";
  }

  return 0;
}