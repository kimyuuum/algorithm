#include <iostream>
using namespace std;
const int MAX = 10001;
int d[MAX];

int main() {
  int n;
  cin >> n;

  d[1] = 1;
  d[2] = 2;

  for (int i = 3; i <= n; i++) {
    d[i] = (d[i - 1] + d[i - 2]) % 10007;
  }

  cout << d[n];

  return 0;
}
