#include <iostream>
using namespace std;
int arr[] = {9, 7, 6, 5, 4, 3, 2, 2, 1, 3, 8};

void heapify(int idx, int size) {
  int target = idx;
  int left = idx * 2;
  int right = idx * 2 + 1;
  if (arr[left] >= arr[target]) {
    target = left;
  }
  if (arr[right] >= arr[target]) {
    target = right;
  }

  if (target != idx) {
    swap(arr[target], arr[idx]);
    heapify(target, size);
  }
}

void buildHeap(int size) {
  for (int i = size / 2; i >= 0; i--) {
    heapify(i, size);
  }
}

int main() {
  buildHeap(11);
  for (int i = 0; i < 11; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}