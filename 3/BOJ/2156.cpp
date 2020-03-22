
#include <algorithm>
#include <iostream>
using namespace std;
const int MAX = 10005;
int arr[MAX];
int d[MAX];

int main() {
  int n;
  cin >> n;
  for (int i = 3; i < n + 3; i++) {
    cin >> arr[i];
  }
  int res = 0;

  for (int i = 3; i < n + 3; i++) {
    int temp = max(d[i - 2] + arr[i], d[i - 3] + arr[i - 1] + arr[i]);
    d[i] = max(temp, d[i - 1]);
    res = max(res, d[i]);
  }

  cout << res;

  return 0;
}