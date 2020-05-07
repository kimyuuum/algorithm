#include <algorithm>
#include <iostream>
using namespace std;
const int MAX = 1002;
int arr[MAX];
int n, m, l;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m >> l;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  arr[0] = 0;
  arr[n + 1] = l;
  sort(arr, arr + n + 1);

  int left = 1;
  int right = l-1;

  while (left <= right) {
    int cnt = 0;
    int mid = (left + right) / 2;

    for (int i = 1; i < n + 2; i++) {
      if (arr[i] - arr[i - 1] >= mid) {
        cnt += (arr[i] - arr[i - 1] - 1) / mid;
      }
    }
    cout << mid << " " << cnt << endl;
    if (cnt > m) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  cout << left;
  return 0;
}