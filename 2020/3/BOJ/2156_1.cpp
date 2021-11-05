
#include <algorithm>
#include <iostream>
using namespace std;
const int MAX = 10001;
int arr[MAX];
int d[MAX];

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  d[1] = arr[1];
  d[2] = d[1] + arr[2];

  for (int i = 3; i <= n; i++) {
    int temp = max(d[i - 2] + arr[i], d[i - 3] + arr[i - 1] + arr[i]);
    d[i] = max(d[i - 1], temp);
  }

  cout << d[n];

  return 0;
}