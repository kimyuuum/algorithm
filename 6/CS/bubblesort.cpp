
#include <iostream>
using namespace std;
int arr[7] = {15, 4, 7, 2, 4, 8, 9};

int main() {
  for (int i = 0; i < 7; i++) {
    for (int j = 1; j < 7 - i; j++) {
      if (arr[j - 1] > arr[j]) {
        swap(arr[j - 1], arr[j]);
      }
    }
  }

  for (int i = 0; i < 7; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}