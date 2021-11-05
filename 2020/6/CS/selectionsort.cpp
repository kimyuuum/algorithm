
#include <iostream>
using namespace std;
int arr[7] = {15, 4, 7, 2, 5, 8, 9};

int main() {
  for (int i = 0; i < 7; i++) {
    int target = i;
    for (int j = i + 1; j < 7; j++) {
      if (arr[target] > arr[j]) {
        target = j;
      }
    }
    swap(arr[target], arr[i]);
  }

  for (int i = 0; i < 7; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}