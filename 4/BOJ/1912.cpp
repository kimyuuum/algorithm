
#include <iostream>
using namespace std;
const int MAX = 100001;
int arr[MAX];
int res, n;
int m = -100000001;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int start = 0, end = 0;
  int temp = 0;
  while (start < n && end < n) {
    temp += arr[end];

    if (temp > m) {
      m = temp;
    }

    if (temp < 0) {
      start = end + 1;
      end = start;
      temp = 0;
    } else {
      end++;
    }

  }
  cout << temp;
  return 0;
}