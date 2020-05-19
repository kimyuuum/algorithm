
#include <iostream>
using namespace std;

string day[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
  int x, y;
  cin >> x >> y;
  int a = 1, b = 1;

  while (1) {
    b += 7;
    if (b > month[a]) {
      b -= month[a];
      a++;
    }

    if (a == x) {
      break;
    }
  }

  int idx = 0;
  if (b < y) {
    idx = (y - b) % 7;
    cout << day[idx];
  } else {
    idx = (b - y) % 7;
    if (idx == 0) {
      cout << day[0];
    } else {
      cout << day[7 - idx];
    }
  }
  return 0;
}
