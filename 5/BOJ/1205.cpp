#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 51;
long long arr[MAX];
int n, p;
long long newnum;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> newnum >> p;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  if (p == n && arr[n - 1] >= newnum) {
    cout << "-1";
  } else {
    if (n == 0) {
      arr[0] = newnum;
      cout << 1;
    } else if (arr[n - 1] > newnum) {
      arr[n] = newnum;
      cout << n + 1;
    } else {
      int rank = 1;
      for (int i = 0; i < n; i++) {
        if (arr[i] > newnum) {
          rank++;
        } else {
          break;
        }
      }
      cout << rank;
    }
  }

  return 0;
}