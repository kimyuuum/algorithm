#include <cstring>
#include <iostream>
using namespace std;
const int MAX = 1001;
bool isPrime[MAX];
int n, k;

void check() {
  memset(isPrime, true, sizeof(isPrime));
  int cnt = 0;
  for (int i = 2; i <= n; i++) {
    if (isPrime[i]) {
      for (int j = i; j <= n; j += i) {
        if (isPrime[j]) {
          isPrime[j] = false;
          cnt++;
        }
        if (cnt == k) {
          cout << j;
          exit(0);
        }
      }
    }
  }
}
int main() {
  cin >> n >> k;
  check();
  return 0;
}