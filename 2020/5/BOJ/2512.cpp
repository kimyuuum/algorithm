#include <iostream>
#include <vector>
using namespace std;
long long n, total, res;
vector<long long> v;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  long long right = 0;
  long long left = 0;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    long long num;
    cin >> num;
    v.push_back(num);
    if (right < num) {
      right = num;
    }
    sum += num;
  }

  cin >> total;
  if (sum <= total) {
    cout << right;
  } else {
    while (left <= right) {
      sum = 0;
      long long mid = (long long)(left + right) / 2;

      for (int i = 0; i < n; i++) {
        if (v[i] >= mid) {
          sum += mid;
        } else {
          sum += v[i];
        }
      }

      if (sum > total) {
        right = mid - 1;
      } else {
        if (mid > res) {
          res = mid;
        }
        left = mid + 1;
      }
    }

    cout << res;
  }
}