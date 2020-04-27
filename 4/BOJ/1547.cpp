
#include <algorithm>
#include <iostream>
using namespace std;
int arr[4] = {0, 1, 2, 3};
int m;

int main() {
  cin >> m;
  while (m--) {
    int x, y;
    cin >> x >> y;
    swap(arr[x], arr[y]);
  }

  for (int i = 1; i <= 3; i++) {
    if (arr[i] == 1) {
      cout << i;
    }
  }

  return 0;
}