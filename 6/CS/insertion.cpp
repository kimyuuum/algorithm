
#include <iostream>
using namespace std;
int arr[7] = {15, 4, 7, 2, 5, 8, 9};

int main() {
  for (int i = 1; i < 7; i++) {
    int j = i - 1;
    while (j >= 0 && arr[j] > arr[j + 1]) {
      swap(arr[j + 1], arr[j]);
      j--;
    }
  }

  for (int i = 0; i < 7; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}