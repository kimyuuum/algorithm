
#include <algorithm>
#include <iostream>
using namespace std;
const int MAX = 100005;
int rope[MAX];
int n;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> rope[i];
  }

  sort(rope, rope + n, greater<int>());

  long long maxk = (long long)rope[0];
  int idx = 1;
  int k = 2;

  while (idx < n) {
    if (rope[idx] * k > maxk) {
      maxk = rope[idx] * k;
    }
    idx++;
    k++;
  }

  cout << maxk;
  return 0;
}