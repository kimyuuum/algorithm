#include <algorithm>
#include <iostream>
using namespace std;
const int MAX = 100005;
int arr[MAX];
int n, m;
int bst(int num) {
  int r = n - 1;
  int l = 0;
  while (l <= r) {
    int mid = (r + l) / 2;
    if (num > arr[mid]) {
      l = mid + 1;
    } else if (num < arr[mid]) {
      r = mid - 1;
    } else {
      return mid;
    }
  }
  return -1;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  cin >> m;
  for (int i = 0; i < m; i++) {
    int num;
    cin >> num;
    if (bst(num) == -1) {
      cout << "0\n";
    } else {
      cout << "1\n";
    }
  }
  return 0;
}