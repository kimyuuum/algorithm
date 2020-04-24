
#include <iostream>
using namespace std;
const int MAX = 100;
long long p[MAX];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int testcase;
  cin >> testcase;

  p[1] = 1;
  p[2] = 1;
  p[3] = 1;
  p[4] = 2;
  p[5] = 2;
  p[6] = 3;

  for (int i = 7; i <= 100; i++) {
    p[i] = p[i - 1] + p[i - 5];
  }

  while (testcase--) {
    int n;
    cin >> n;
    cout << p[n] << "\n";
  }

  return 0;
}