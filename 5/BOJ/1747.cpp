#include <cstring>
#include <iostream>
using namespace std;
const int MAX = 2000000;
bool isPrime[MAX];
int n;

void checkPrime() {
  memset(isPrime, true, sizeof(isPrime));
  isPrime[1] = false;
  for (int i = 2; i * i <= MAX; i++) {
    if (!isPrime[i]) {
      continue;
    }
    for (int j = i * i; j <= MAX; j += i) {
      isPrime[j] = false;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  checkPrime();

  for (int i = n; i < MAX; i++) {
    bool flag = true;
    if (isPrime[i]) {
      string num = to_string(i);
      int idx = 0;
      while (idx < num.size() / 2) {
        if (num[idx] != num[num.size() - idx - 1]) {
          flag = false;
          break;
        }
        idx++;
      }
      if (flag) {
        cout << i;
        break;
      }
    }
  }

  return 0;
}