
#include <iostream>
using namespace std;
const int MAX = 40;
int d[MAX][2];

int main() {
  int t, n;
  cin >> t;
  d[0][0] = 1;
  d[0][1] = 0;
  d[1][0] = 0;
  d[1][1] = 1;

  for (int i = 0; i < t; i++) {
    cin >> n;
    for (int j = 2; j <= n; j++) {
      d[j][0] = d[j - 2][0] + d[j - 1][0];
      d[j][1] = d[j - 2][1] + d[j - 1][1];
    }
    cout << d[n][0] << " " << d[n][1] << "\n";
  }

  return 0;
}