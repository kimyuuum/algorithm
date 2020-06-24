
#include <iostream>
using namespace std;
const int MAX = 100;
int arr[15] = {0, 1, 1, 3, 5, 2, 4, 2, 5, 8, 9, 7, 0, 6, 3};
int cnt[10];
int res[15];

int main() {
  for (int i = 0; i < 15; i++) {
    cnt[arr[i]]++;
  }

  for (int i = 1; i < 10; i++) {
    cnt[i] += cnt[i - 1];
  }

  for (int i = 0; i < 15; i++) {
    res[cnt[arr[i]]] = arr[i];
    cnt[arr[i]]--;
  }

  for (int i = 1; i <= 15; i++) {
    cout << res[i] << " ";
  }
  return 0;
}