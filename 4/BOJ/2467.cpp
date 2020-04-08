
#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;
const int MAX = 100000;
int n, resl, resr;
long long minimum;
long long arr[MAX];

void binarySearch() {
  int l = 0;
  int r = n - 1;
  while (l < r) {
    long long sum = arr[l] + arr[r];
    if (llabs(sum) < llabs(minimum)) {
      minimum = sum;
      resl = l;
      resr = r;
    }
    if (sum > 0) {
      r--;
    } else {
      l++;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  minimum = LLONG_MAX;
  binarySearch();
  cout << arr[resl] << " " << arr[resr];
  return 0;
}