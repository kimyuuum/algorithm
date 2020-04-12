#include <iostream>
using namespace std;
int n;

int main() {
  cin >> n;
  int i = 2;

  while (i * i <= n) {
    if (n % i == 0) {
      cout << i << "\n";
      n /= i;
    } else {
      i++;
    }
  }
  if (n != 1) {
    cout << n << "\n";
  }

  return 0;
}
