
#include <algorithm>
#include <iostream>
using namespace std;
const int MAX = 500000;
int arr[MAX];
int n, m;

int binarySearch(int num) {
  int l = 0;
  int r = n - 1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (arr[mid] < num) {
      l = mid + 1;
    } else if (arr[mid] > num) {
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
  int num;
  for (int i = 0; i < m; i++) {
    cin >> num;
    if (binarySearch(num) == -1) {
      cout << "0 ";
    } else {
      cout << "1 ";
    }
  }
  return 0;
}