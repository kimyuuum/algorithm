
#include <iostream>
#include <vector>
using namespace std;
long long n, k, ans;
vector<long long> v;

bool cut(long long len) {
  long long sum = 0;

  for (long long i = 0; i < k; i++) {
    sum += v[i] / len;
    if (sum >= n) {
      return true;
    }
  }

  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> k >> n;
  long long right = 0, left = 1;

  for (long long i = 0; i < k; i++) {
    long long num;
    cin >> num;
    v.push_back(num);
    if (right < num) {
      right = num;
    }
  }

  while (left <= right) {
    long long mid = (long long)(left + right) / 2;

    if (cut(mid)) {
      if (ans < mid) {
        ans = mid;
      }
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  cout << ans;
  return 0;
}