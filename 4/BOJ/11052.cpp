
#include <iostream>
using namespace std;
const int MAX = 1001;
int d[MAX];
int p[MAX];
int n;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }
  d[1] = p[1];

  for (int i = 2; i <= n; i++) {
    d[i] = p[i];
    for (int j = i - 1; j >= 1; j--) {
      d[i] = max(d[i], d[j] + d[i - j]);
    }
  }

  cout << d[n];
  return 0;
}