
#include <iostream>
using namespace std;
int arr[] = {8, 5, 6, 2, 4};

int main() {
  for (int i = 1; i < 5; i++) {
    int j = i - 1;
    while (j >= 0 && arr[j] > arr[j + 1]) {
      swap(arr[j], arr[j + 1]);
      j--;
    }
  }

  for (int i = 0; i < 5; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}