#include <iostream>
using namespace std;
const int MAX = 1000000001;
int n, l;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> l;

  int left = 0;
  int right = 1;
  long long sum = 1;
  bool flag = false;

  int res = MAX;
  int rl = 0;
  int rr = 0;

  while (right < MAX && left <= right) {
    int len = right - left + 1;

    if (sum < n) {
      right++;
      sum += right;
    } else if (sum > n) {
      sum -= left;
      left++;
      if (left >= right) {
        right = left + 1;
        sum = left + right;
      }
    } else if (sum == n) {
      if (res > len && len >= l) {
        rl = left;
        rr = right;
        res = len;
      }
      sum -= left;
      left++;
    }
  }

  if (res > 100) {
    cout << -1;
  } else {
    for (int i = rl; i <= rr; i++) {
      cout << i << " ";
    }
  }

  return 0;
}
