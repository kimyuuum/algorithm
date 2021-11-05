#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 200002;
int cnt[MAX];
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
  vector<int> A = {1, 2, 1};
  for (int i = 0; i < A.size(); i++) {
    int num = A[i];
    cnt[num]++;
    if (cnt[num] > 1) {
      pq.push(num);
    }
  }

  int n = A.size();
  int res = 0;
  while (!pq.empty()) {
    for (int i = 1; i <= n; i++) {
      if (cnt[i] == 0) {
        res += abs(pq.top() - i);
        pq.pop();
        cnt[i]++;
        break;
      }
    }

    if (res > 1000000000) {
      res = -1;
      break;
    }
  }
  cout << res;
}