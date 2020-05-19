
#include <iostream>
using namespace std;

int main() {
  int h, m;

  cin >> h >> m;

  if (m < 45) {
    h--;
    m = m + 60 - 45;
    if (h < 0) {
      h = 23;
    }
    cout << h << " " << m;
  } else {
    cout << h << " " << m - 45;
  }

  return 0;
}