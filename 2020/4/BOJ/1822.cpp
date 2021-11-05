
#include <algorithm>
#include <iostream>
using namespace std;
const int MAX = 500000;
int arr[MAX];
int n, m;
bool visited[MAX];
int cnt;

void binarySearch(int target) {
  int r = n - 1;
  int l = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (arr[mid] < target) {
      l = mid + 1;
    } else if (arr[mid] > target) {
      r = mid - 1;
    } else {
      visited[mid] = true;
      cnt++;
      return;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int num;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  for (int i = 0; i < m; i++) {
    cin >> num;
    binarySearch(num);
  }
  if (cnt == n) {
    cout << "0";
  } else {
    cout << n - cnt << "\n";
    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        cout << arr[i] << " ";
      }
    }
  }
  return 0;
}