#include <iostream>
using namespace std;
const int MAX = 91;
long long fibo[MAX];
int n;

int main() {
  fibo[1] = 1;
  fibo[0] = 0;
  cin >> n;

  for (int i = 2; i <= n; i++) {
    fibo[i] = fibo[i - 1] + fibo[i - 2];
  }

  cout << fibo[n];
}