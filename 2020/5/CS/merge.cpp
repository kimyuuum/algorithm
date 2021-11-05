#include <iostream>
#include <vector>
using namespace std;
vector<int> v;

void merge(int start, int mid, int end) {
  vector<int> res;
  int i = start;
  int j = mid + 1;
  int idx = 0;
  while (i <= mid && j <= end) {
    if (v[i] <= v[j]) {
      res.push_back(v[i]);
      i++;
    } else {
      res.push_back(v[j]);
      j++;
    }
  }

  while (i <= mid) {
    res.push_back(v[i]);
    i++;
  }
  while (j <= end) {
    res.push_back(v[j]);
    j++;
  }

  for (int i = start; i <= end; i++) {
    v[i] = res[idx++];
  }
}

void mergesort(int start, int end) {
  if (start < end) {
    int mid = (start + end) / 2;
    mergesort(start, mid);
    mergesort(mid + 1, end);
    merge(start, mid, end);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    v.push_back(num);
  }

  mergesort(0, n - 1);
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << "\n";
  }
  return 0;
}