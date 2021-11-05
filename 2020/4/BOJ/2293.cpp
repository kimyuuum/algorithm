
#include <iostream>
using namespace std;
const int MAX = 101;
const int M = 10001;
int coin[MAX];
int d[M];

int main() {
  int n, k;
  cin >> n >> k;

  for (int i = 1; i <= n; i++) {
    cin >> coin[i];
  }

  d[0] = 1;

  for (int i = 1; i <= n; i++) {
    for (int j = coin[i]; j <= k; j++) {
      d[j] = d[j] + d[j - coin[i]];
    }
  }

  cout << d[k];

  return 0;
}