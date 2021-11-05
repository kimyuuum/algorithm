
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int testcase;
  cin >> testcase;
  while (testcase--) {
    int n, target, res = -1;
    queue<pair<int, int>> q;
    priority_queue<int> pq;

    cin >> n >> target;

    for (int i = 0; i < n; i++) {
      int idx;
      cin >> idx;

      q.push(make_pair(idx, i));
      pq.push(idx);
    }

    int cnt = 1;

    while (!q.empty()) {
      int pri = q.front().first;
      int idx = q.front().second;
      
      q.pop();

      if (pq.top() == pri) {
        if (target == idx) {
          res = cnt;
        } else {
          pq.pop();
          cnt++;
        }
      } else {
        q.push(make_pair(pri, idx));
      }

      if(res != -1){
        break;
      }
    }

    cout << res << endl;
  }

  return 0;
}