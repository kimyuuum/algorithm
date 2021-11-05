
#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;
const int MAX = 100000;
long long arr[MAX];
int n;
long long result;

void binarySearch() {
  int l = 0;
  int r = n - 1;

  while (l < r) {
    long long sum = arr[l] + arr[r];
    if (llabs(sum) < llabs(result)) {
      result = sum;
    }
    if (sum < 0) {
      l++;
    } else{
      r--;
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

  result = LLONG_MAX;
  binarySearch();
  cout << result;
  return 0;
}