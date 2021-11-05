
#include <cmath>
#include <iostream>
using namespace std;
int n, r, c;
int num;

void zet(int x, int y, int size) {
  if (x == r && y == c) {
    cout << num << "\n";
    exit(0);
  }
  if (size == 1) {
    num++;
    return;
  }
  if (!(x <= r && r < x + size && y <= c && c < y + size)) {
    num += size * size;
    return;
  }

  int s = size / 2;
  zet(x, y, s);
  zet(x, y + s, s);
  zet(x + s, y, s);
  zet(x + s, y + s, s);
}

int main() {
  cin >> n >> r >> c;
  zet(0, 0, pow(2, n));

  return 0;
}