#include <iostream>
#include <vector>
using namespace std;
vector<int> v = {31, 8, 48, 73, 11, 3, 20, 29, 65, 15};

void sortThree(int left, int mid, int right) {
  if (v[left] > v[mid]) {
    swap(v[left], v[mid]);
  }
  if (v[left] > v[right]) {
    swap(v[left], v[right]);
  }
  if (v[mid] > v[right]) {
    swap(v[mid], v[right]);
  }
}

int partition(int left, int right) {
  int mid = (left + right) / 2;
  sortThree(left, mid, right);
  int pivot = v[mid];
  int i = left + 1;
  int j = right - 2;

  swap(v[mid], v[right - 1]);

  while (i < j) {
    while (v[i] <= pivot && i <= right - 1) {
      i++;
    }
    while (v[j] > pivot && j > left) {
      j--;
    }
    if (i >= j) {
      swap(v[i], v[right - 1]);
    } else {
      swap(v[i], v[j]);
    }
  }

  return i;
}

void quick(int left, int right) {
  if (left < right) {
    int q = partition(left, right);
    quick(left, q - 1);
    quick(q + 1, right);
  }
}

int main() {
  quick(0, 9);
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  return 0;
}