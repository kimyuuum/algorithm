
#include <algorithm>
#include <iostream>
using namespace std;
const int MAX = 500005;
int n, m;
int arr[MAX];

int upper_idx(int num) {
  int r = n;
  int l = 0;
  while (l < r) {
    int mid = (l + r) / 2;
    if (arr[mid] <= num) {
      l = mid + 1;
    } 
    else{
      r = mid;
    }
  }
  return l;
}

int lower_idx(int num) {
  int r = n;
  int l = 0;
  while (l < r) {
    int mid = (l + r) / 2;
    if (arr[mid] < num) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  return l;
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
    cout << upper_idx(num) - lower_idx(num) << " ";
  }
  return 0;
}