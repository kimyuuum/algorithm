
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 11;
int arr[MAX];
char op[12];
vector<int> v;

int main() {
  int n, num;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < 4; i++) {
    cin >> num;
    for (int j = 0; j < num; j++) {
      v.push_back(i);
    }
  }

  int max = -1000000000;
  int min = 1000000000;

  do {
    int res;
    for (int i = 1; i < n; i++) {
      if (i == 1) {
        if (v[i - 1] == 0) {
          res = arr[i - 1] + arr[i];
        } else if (v[i - 1] == 1) {
          res = arr[i - 1] - arr[i];
        } else if (v[i - 1] == 2) {
          res = arr[i - 1] * arr[i];
        } else {
          res = arr[i - 1] / arr[i];
        }
      } else {
        if (v[i - 1] == 0) {
          res = res + arr[i];
        } else if (v[i - 1] == 1) {
          res = res - arr[i];
        } else if (v[i - 1] == 2) {
          res = res * arr[i];
        } else {
          res = res / arr[i];
        }
      }
    }
    if (max < res) max = res;
    if (min > res) min = res;
  } while (next_permutation(v.begin(), v.end()));

  cout << max << "\n" << min;

  return 0;
}