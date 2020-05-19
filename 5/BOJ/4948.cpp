#include <cstring>
#include <iostream>
using namespace std;
const int MAX = 123456 * 2;
bool isPrime[MAX];

void check() {
  memset(isPrime, true, sizeof(isPrime));
  isPrime[1] = false;

  for (int i = 2; i * i <= MAX; i++) {
    if (isPrime[i]) {
      for (int j = i * i; j <= MAX; j += i) {
        isPrime[j] = false;
      }
    }
  }
}

int main() {
  int num;
  check();
  while (1) {
    cin >> num;
    if (num == 0) {
      break;
    }
    int cnt = 0;
    for (int i = num + 1; i <= 2 * num; i++) {
      if (isPrime[i]) {
        cnt++;
      }
    }
    cout << cnt << "\n";
  }
  return 0;
}