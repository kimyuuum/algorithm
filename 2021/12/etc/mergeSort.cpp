#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int arr[9] = {5, 3, 8, 4, 9, 1, 6, 2, 7};

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
  quicksort(0, 8);
  for (int i = 0; i < 9; i++) {
    cout << arr[i] << " ";
  }
}