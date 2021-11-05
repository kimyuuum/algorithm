
#include <iostream>
using namespace std;
const int MAX = 11;
int p[MAX];
int n, k;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> k;

  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }
  p[0] = 0;
  int target = n;
  int cnt = 0;

  while (k != 0) {
    while (k >= p[target]) {
      k -= p[target];
      cnt++;
    }

    target--;
  }

  cout << cnt;

  return 0;
}