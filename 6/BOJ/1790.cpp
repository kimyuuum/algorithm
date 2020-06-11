#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
long long n, k, m;
long long len, ans;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;

  long long temp = n;
  int cnt = 0;
  while (temp != 0) {
    temp /= 10;
    cnt++;
  }

  for (int i = 1; i < cnt; i++) {
    len += (long long)powl(10, i - 1) * 9 * i;
  }
  m = len;
  long long num = n - powl(10, cnt - 1) + 1;
  len += num * cnt;

  if (len < k) {
    cout << -1;
  } else {
    long long temp;
    int nine = 9;
    int num = 1;
    while (k >= (nine * num)) {
      temp += (nine * num);
      nine *= 10;
      num++;
    }
    k -= (temp + 1);
    ans = powl(10, num - 1);
    ans += (k / num);
    string a = to_string(ans);
    cout << a[(k % num)];
  }

  return 0;
}