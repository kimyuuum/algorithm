
#include <cmath>
#include <iostream>
using namespace std;
int a, b, c;
long long res;

long long func(int a, int b) {
  if (b == 1) {
    return a;
  } else if (b == 0) {
    return 1;
  }

  if (b % 2 == 0) {
    long long temp = func(a, b / 2);
    return (temp * temp) % c;
  } else if (b % 2 != 0) {
    long long temp = func(a, (b - 1) / 2);
    return (((temp * temp) % c) * a) % c;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> a >> b >> c;
  res = func(a % c, b);
  cout << res;
  return 0;
}