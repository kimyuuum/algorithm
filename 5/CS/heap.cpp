#include <iostream>
using namespace std;
const int MAX = 1000001;
int arr[MAX];
int n;

void insertion(int el, int idx) {
  int target = el;
  int now = idx;
  while (now >= 1) {
    int parent = now / 2;
    if (parent >= 1 && arr[parent] >= target) {
      swap(arr[parent], arr[now]);
      now /= 2;
    } else {
      break;
    }
  }
}

void deletion() {
  arr[1] = arr[n];
  n--;
  int target = 1;

  while (target * 2 + 1 <= n) {
    int left = target * 2;
    int right = target * 2 + 1;

    if (arr[left] < arr[right]) {
      swap(arr[left], arr[target]);
      target = left;
    } else {
      swap(arr[right], arr[target]);
      target = right;
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << arr[i] << " ";
  }
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    insertion(arr[i], i);
  }

  for (int i = 1; i <= n; i++) {
    cout << arr[i] << " ";
  }

  cout << endl;
  deletion();

  return 0;
}