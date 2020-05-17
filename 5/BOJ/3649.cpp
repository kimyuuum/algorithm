#include <algorithm>
#include <iostream>
using namespace std;
const int MAX = 1000001;
int x, n;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while (cin >> x) {
    cin >> n;
    int arr[MAX];
    bool flag = false;

    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    sort(arr, arr + n);
    x *= 10000000;

    int left = 0;
    int right = n - 1;

    int val = 0;
    int l1 = 0, l2 = 0;

    while (left < right) {
      int w = arr[left] + arr[right];
      if (w < x) {
        left++;
      } else if (w > x) {
        right--;
      } else {
        flag = true;
        break;
      }
    }

    if (flag) {
      cout << "yes " << arr[left] << " " << arr[right] << "\n";
    } else {
      cout << "danger\n";
    }
  }
  return 0;
}