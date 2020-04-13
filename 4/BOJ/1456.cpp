
#include <iostream>
#include <vector>
using namespace std;
const long long MAX = 100000005;
bool arr[MAX];
vector<long long> prime;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  long long a, b;
  cin >> a >> b;

  for (long long i = 2; i * i <= MAX; i++) {
    for (long long j = i * i; j <= MAX; j += i) {
      if (!arr[j]) {
        arr[j] = true;
      }
    }
  }

  int cnt = 0;
  for (long long i = 2; i <= MAX; i++) {
    if (!arr[i]) {
      long long num = i * i;
      int p = 2;
      int maxp = 100;
      while (p <= maxp && num <= b) {
        if (num >= a) cnt++;
        num *= i;
        p++;
      }
      maxp = p - 1;
      if (maxp == 1) break;
    }
  }

  cout << cnt;
  return 0;
}