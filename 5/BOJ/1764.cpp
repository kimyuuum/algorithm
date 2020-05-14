#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 500001;
string arr[MAX];
int n, m;
vector<string> v;

bool binarySearch(string input) {
  int left = 0;
  int right = n - 1;

  while (left <= right) {
    int mid = (left + right) / 2;
    int res = arr[mid].compare(input);
    if (res == 0) {
      return true;
    } else if (res < 0) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);

  while (m--) {
    string input;
    cin >> input;
    if (binarySearch(input)) {
      v.push_back(input);
    }
  }

  sort(v.begin(), v.end());
  cout << v.size() << "\n";
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << "\n";
  }
  return 0;
}