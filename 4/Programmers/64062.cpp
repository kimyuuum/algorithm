#include <string>
#include <vector>
using namespace std;

bool isPossible(int mid, const vector<int>& stones, int k) {
  int cur = 0;
  for (int i = 0; i < stones.size(); i++) {
    if (stones[i] - mid <= 0) {
      cur++;
    } else
      cur = 0;
    if (cur >= k) return false;
  }
  return true;
}

int solution(vector<int> stones, int k) {
  int r = 200000000;
  int l = 1;
  while (l <= r) {
    int mid = (r + l) / 2;
    if (isPossible(mid, stones, k)) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  return l;
}

