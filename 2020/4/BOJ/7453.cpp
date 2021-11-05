
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 4000;
int arr[4][MAX];
int a[MAX * MAX];
int b[MAX * MAX];
int n, idx;
long long result;

void binarySearch() {
  int l = 0;
  int r = idx - 1;
  while (l < idx && r >= 0) {
    if (a[l] + b[r] == 0) {
      int lidx = l;
      long long lcnt = 0, rcnt = 0;
      while (a[l] + b[r] == 0) {
        if (l >= idx) break;
        lcnt++;
        l++;
      }
      while (a[lidx] + b[r] == 0) {
        if (r < 0) break;
        rcnt++;
        r--;
      }
      result += (long long)(lcnt * rcnt);

    } else if (a[l] + b[r] < 0) {
      l++;
    } else if (a[l] + b[r] > 0) {
      r--;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  int num;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> arr[j][i];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a[idx] = (arr[0][i] + arr[1][j]);
      b[idx] = (arr[2][i] + arr[3][j]);
      idx++;
    }
  }
  sort(a, a + idx);
  sort(b, b + idx);
  binarySearch();

  cout << result;
  return 0;
}