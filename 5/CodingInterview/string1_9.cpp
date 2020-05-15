
#include <cstring>
#include <iostream>
using namespace std;

bool isSubstring(string a, string b) {
  for (int i = 0; i < b.size(); i++) {
    if (b[i] == a[0]) {
      int left = i;
      int right = i + 1;
      int idx = 1;
      while (left != right) {
        if (right == b.size()) {
          right = 0;
        }
        if (a[idx] == b[right]) {
          idx++;
          right++;
        } else {
          left++;
        }

        if (left == b.size()) {
          return false;
        }
      }
      return true;
    }
  }
}

int main() {
  string a, b;
  cin >> a >> b;
  if (isSubstring(a, b)) {
    cout << "true";
  } else {
    cout << "false";
  }

  return 0;
}