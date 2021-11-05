
#include <iostream>
using namespace std;

int main() {
  int h = 2000, l = 2000;

  for (int i = 0; i < 3; i++) {
    int num;
    cin >> num;
    if (num < h) {
      h = num;
    }
  }

  for (int i = 0; i < 2; i++) {
    int num;
    cin >> num;
    if (num < l) {
      l = num;
    }
  }

  cout << h + l - 50;
  return 0;
}