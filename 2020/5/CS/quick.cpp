#include <iostream>
#include <vector>
using namespace std;
vector<int> v = {31, 8, 48, 73, 11, 3, 20, 29, 65, 15};

int partition(int left, int right) {
  int pivot = v[left];
  int low = left + 1;
  int high = right;
  
  while (low < high) {
    while (low <= right && v[low] <= pivot) {
      low++;
    }
    while (high > left && v[high] > pivot) {
      high--;
    }

    if (low > high) {
      swap(v[left], v[high]);
    } else {
      swap(v[low], v[high]);
    }
  }

  return high;
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