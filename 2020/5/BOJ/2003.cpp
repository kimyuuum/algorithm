
#include <iostream>
using namespace std;
const int MAX = 10005;
int arr[MAX];
int n, m;

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int left = 0;
  int right = 0;
  int sum = arr[0];
  int cnt = 0;

  while (right < n && left <= right) {
    if (sum == m) {
      cnt++;
      sum -= arr[left];
      left++;
      if (left > right) {
        right = left;
        sum += arr[right];
      }
    } else if (sum < m) {
      right++;
      sum += arr[right];
    } else if (sum > m) {
      sum -= arr[left];
      left++;
      if (left > right) {
        right = left;
        sum += arr[right];
      }
    }
  }
  cout << cnt;
  return 0;
}
