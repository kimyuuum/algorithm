
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 2000;
long arr[MAX];
int n;
vector<long> v;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  sort(arr, arr + n);

  for (int i = 0; i < n; i++) {
    long target = arr[i];
    int l = 0;
    int r = n - 1;

    while (l < r) {
      long sum = arr[l] + arr[r];
      if (sum == target) {
        if (l != i && r != i) {
          v.push_back(target);
          break;
        } else {
          if (l == i) {
            l++;
          } else if (r == i) {
            r--;
          }
        }
      } else if (sum > target) {
        r--;
      } else {
        l++;
      }
    }
  }

  cout << v.size();
  return 0;
}