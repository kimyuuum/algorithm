
#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  int two = 0, five = 0;

  cin >> n;
  for (int i = 1; i <= n; i++) {
    int num = i;
    while (num % 2 == 0 && num > 1) {
      two++;
      num /= 2;
    }

    while (num % 5 == 0 && num > 1) {
      five++;
      num /= 5;
    }
  }

  cout << min(two, five);

  return 0;
}