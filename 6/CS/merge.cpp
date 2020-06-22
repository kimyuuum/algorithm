#include <iostream>
#include <vector>
using namespace std;
int arr[7] = {15, 4, 7, 2, 5, 8, 9};

void merge(int left, int mid, int right) {
  int i = left;
  int j = mid + 1;
  vector<int> v;

  while (i <= mid && j <= right) {
    if (arr[i] <= arr[j]) {
      v.push_back(arr[i++]);
    } else {
      v.push_back(arr[j++]);
    }
  }

  while (i <= mid) {
    v.push_back(arr[i++]);
  }
  while (j <= right) {
    v.push_back(arr[j++]);
  }

  int cnt = 0;
  for (int i = left; i <= right; i++) {
    arr[i] = v[cnt++];
  }
}

void mergesort(int left, int right) {
  if (left < right) {
    int mid = (left + right) / 2;
    mergesort(left, mid);
    mergesort(mid + 1, right);
    merge(left, mid, right);
  }
}
int main() {
  mergesort(0, 6);
  for (int i = 0; i < 7; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}