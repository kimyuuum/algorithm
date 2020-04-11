

#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main() {
  string a, b;
  bool flag = true;
  cin >> a >> b;
  int size = a.size() - b.size();
  if (abs(size) >= 2) {
    flag = false;
  } else if (size == 0) {
    int cnt = 0;
    for (int i = 0; i < a.size(); i++) {
      if (a[i] != b[i]) {
        cnt++;
      }
      if (cnt >= 2) {
        flag = false;
        break;
      }
    }
  } else if (size == 1) {
    int aIdx = 0, bIdx = 0;
    int cnt = 0;
    while (aIdx < a.size() && bIdx < b.size()) {
      if (a[aIdx] != b[bIdx]) {
        cnt++;
        if (a.size() > b.size()) {
          aIdx++;
        } else {
          bIdx++;
        }
      } else {
        aIdx++;
        bIdx++;
      }
      if (cnt >= 2) {
        flag = false;
        break;
      }
    }
  }

  if (!flag) {
    cout << "false";
  } else {
    cout << "true";
  }
  return 0;
}