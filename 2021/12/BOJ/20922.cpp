#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100001;
int cnt[MAX] = {
    0,
};

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> v;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v.push_back(x);
  }

  int leftIdx = 0;
  int rightIdx = 0;

  cnt[v[leftIdx]]++;
  int res = 1;

  while (leftIdx != v.size() - 2 && rightIdx != v.size() - 1) {
    int nextIdx = rightIdx + 1;

    if (nextIdx <= v.size() - 1) {
      int num = v[nextIdx];

      if (cnt[num] < k) {
        int len = nextIdx - leftIdx + 1;
        if (len > res) {
          res = len;
        }
        rightIdx++;
        cnt[num]++;
      } else {
        while (cnt[num] != k - 1) {
          int leftNum = v[leftIdx];
          cnt[leftNum]--;
          leftIdx++;
        }
        if (leftIdx >= rightIdx) {
          rightIdx = leftIdx + 1;
          cnt[v[leftIdx]] = 1;
          cnt[v[rightIdx]] = 1;
        } else {
          rightIdx++;
          cnt[num]++;
        }
      }
    }
  }

  cout << res;

  return 0;
}