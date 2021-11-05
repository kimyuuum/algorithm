
#include <iostream>
using namespace std;
const int MAX = 1000001;
long long arr[MAX];
long long res, n, a, b;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cin >> a >> b;

  for (long long i = 0; i < n; i++) {
    long long num = arr[i];
    num -= a;
    res++;
    if (num > 0) {
      if (num % b == 0) {
        res += (num / b);
      } else {
        res += (num / b) + 1;
      }
    }
  }
  cout << res;
  return 0;
}