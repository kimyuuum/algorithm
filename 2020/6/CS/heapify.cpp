#include <iostream>
#include <vector>
using namespace std;
vector<int> arr;

void heapify(int idx, int size) {
  int target = idx;
  int left = idx * 2 + 1;
  int right = idx * 2 + 2;

  if (arr[left] > arr[target]) {
    target = left;
  }
  if (arr[right] > arr[target]) {
    target = right;
  }

  if (idx != target) {
    swap(arr[idx], arr[target]);
    heapify(target, size);
  }
}
void heapsort(int size) {
  for (int i = (size - 1) / 2; i >= 0; i--) {
    heapify(i, size);
  }
}

void insertion(int idx) {
  while (idx > 0) {
    int parent = (idx - 1) / 2;
    if (arr[idx] > arr[parent]) {
      swap(arr[idx], arr[parent]);
      idx = parent;
    }
  }
}

int main() {
  arr = {4, 14, 7, 2, 15, 1};
  int size = arr.size();
  heapsort(size);
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  arr.push_back(30);
  insertion(6);
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  }
  return 0;
}