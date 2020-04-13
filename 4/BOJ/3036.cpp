
#include <iostream>
using namespace std;
int res;

void gcd(int a, int b) {
  if (b == 0) {
    res = a;
    return;
  }
  gcd(b, a % b);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int first, num, n;
  cin >> n;
  cin >> first;
  n--;
  while (n--) {
    cin >> num;
    gcd(first, num);
    cout << first / res << "/" << num / res << "\n";
  }
  return 0;
}