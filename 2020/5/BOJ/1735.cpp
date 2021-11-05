#include <algorithm>
#include <iostream>
using namespace std;
int arr[2][2];

int gcd(int num1, int num2) {
  int ans = 1;
  while (1) {
    if (ans % num1 == 0 && ans % num2 == 0) {
      return ans;
    }
    ans++;
  }
}

int lcm(int num1, int num2) {
  int ans = min(num1, num2);
  while (1) {
    if (num1 % ans == 0 && num2 % ans == 0) {
      return ans;
    }
    ans--;
  }
}
int main() {
  cin >> arr[0][0] >> arr[0][1];
  cin >> arr[1][0] >> arr[1][1];

  int mom = gcd(arr[0][1], arr[1][1]);
  int son = ((mom / arr[0][1]) * arr[0][0]) + ((mom / arr[1][1]) * arr[1][0]);
  int div = lcm(mom, son);
  mom /= div;
  son /= div;

  cout << son << " " << mom;
  return 0;
}