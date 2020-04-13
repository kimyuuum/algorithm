
#include <iostream>
using namespace std;
const int E = 15;
const int S = 28;
const int M = 19;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int e, s, m;
  cin >> e >> s >> m;

  for (int i = e; i <= (E * S * M); i += E) {
    if (S == s) {
      s = 0;
    }
    if (M == m) {
      m = 0;
    }
    if (i % S == s && i % M == m) {
      cout << i;
      break;
    }
  }

  return 0;
}