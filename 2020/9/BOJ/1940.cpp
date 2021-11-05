#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> v;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, target;
  cin >> n >> target;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    v.push_back(num);
  }

  sort(v.begin(), v.end());

  int lidx = 0;
  int ridx = v.size() - 1;
  int answer = 0;

  while (lidx < ridx) {
    int res = v[lidx] + v[ridx];
    if (res == target) {
      answer++;
      lidx++;
      ridx--;
    } else if (res < target) {
      lidx++;
    } else {
      ridx--;
    }
  }
  cout << answer;
  return 0;
}