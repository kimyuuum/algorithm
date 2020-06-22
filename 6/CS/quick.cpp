#include <iostream>
using namespace std;
int arr[7] = {15, 4, 7, 2, 5, 8, 9};

int partition(int left, int right) {
  int pivot = arr[left];
  int low = left + 1;
  int high = right;

  while (low <= high) {
    while (arr[low] <= pivot && low <= right) {
      low++;
    }
    while (arr[high] >= pivot && high > left) {
      high--;
    }

    if (low > high) {
      swap(arr[left], arr[high]);
    } else {
      swap(arr[low], arr[high]);
    }
  }

  return high;
}

void quicksort(int left, int right) {
  if (left < right) {
    int q = partition(left, right);
    quicksort(left, q - 1);
    quicksort(q + 1, right);
  }
}
int main() {
  quicksort(0, 6);

  for (int i = 0; i < 7; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}