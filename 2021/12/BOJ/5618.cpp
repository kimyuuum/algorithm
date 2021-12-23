#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  int a, b, c;
  int mVal = 0;

  cin >> n;
  if (n == 2) {
    cin >> a >> b;
    mVal = min(a, b);
  } else if (n == 3) {
    cin >> a >> b >> c;
    mVal = min(a, b);
    mVal = min(mVal, c);
  }

  vector<int> v;

  for (int num = 1; num <= mVal; num++) {
    if (n == 2) {
      if (a % num == 0 && b % num == 0) {
        v.push_back(num);
      }
    } else if (n == 3) {
      if ((a % num == 0 && b % num == 0) && c % num == 0) {
        v.push_back(num);
      }
    }
  }

  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << endl;
  }

  return 0;
}