
#include <algorithm>
#include <iostream>
using namespace std;
const int MAX = 1000001;
long long arr[MAX];
int n, m, h;

bool cut(long long height) {
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] > height) {
      sum += arr[i] - height;
    }
    if (sum >= m) {
      return true;
    }
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  long long right = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (right < arr[i]) {
      right = arr[i];
    }
  }

  long long left = 0;

  while (left <= right) {
    long long height = (left + right) / 2;

    if (cut(height)) {
      if (h < height) {
        h = height;
      }
      left = height + 1;
    } else {
      right = height - 1;
    }
  }

  cout << h;

  return 0;
}