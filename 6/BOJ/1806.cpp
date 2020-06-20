#include <iostream>
using namespace std;
const int MAX = 100001;
long long n, s;
int v[MAX];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  int left = 0;
  int right = 0;
  int ans = 987654321;

  long long sum = v[0];
  if (sum == s) {
    ans = 1;
  } else {
    while (left < n && right < n) {
      if (sum < s) {
        right++;
        sum += (long long)v[right];
      } else if (sum >= s) {
        if (right - left + 1 < ans) {
          ans = right - left + 1;
        }

        sum -= (long long)v[left];
        left++;
        if (left >= right) {
          sum = (long long)v[left];
          right = left;
        }
      }
      if (ans == 1) {
        break;
      }
    }
  }

  if (ans == 987654321) {
    cout << 0;
  } else {
    cout << ans;
  }
  return 0;
}