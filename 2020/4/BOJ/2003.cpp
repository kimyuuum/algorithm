
#include <iostream>
using namespace std;
const int MAX = 10000;
int arr[MAX];
int n, m, result;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int low = 0, high = 0;
  int sum = arr[0];

  while (low <= high && high < n) {
    if (sum < m) {
      high++;
      sum += arr[high];
    } else if (sum == m) {
      result++;
      high++;
      sum += arr[high];
    } else if (sum > m) {
      sum -= arr[low];
      low++;
      if (low > high && low < n) {
        high = low;
        sum = arr[low];
      }
    }
  }

  cout << result;
  return 0;
}