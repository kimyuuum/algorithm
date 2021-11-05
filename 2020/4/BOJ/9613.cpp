
#include <cstring>
#include <iostream>
using namespace std;
const int MAX = 100;
int arr[MAX];
long long res;

void gcd(int a, int b) {
  if (b == 0) {
    res += a;
    return;
  }
  gcd(b, a % b);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int testcase, n;
  cin >> testcase;
  while (testcase--) {
    res = 0;
    cin >> n;
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
        gcd(arr[i], arr[j]);
      }
    }
    cout << res << "\n";
  }

  return 0;
}