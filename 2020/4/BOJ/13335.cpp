#include <iostream>
#include <queue>
using namespace std;
queue<pair<int, int>> q;
queue<int> truck;
int n, w, l;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> w >> l;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    truck.push(t);
  }

  int sec = 1;
  int weight = 0;
  while (!truck.empty() || !q.empty()) {
    if (q.empty()) {
      int t = truck.front();
      truck.pop();
      q.push(make_pair(t, sec));
      weight += t;
    } else {
      int nowsec = q.front().second;
      if (nowsec + w == sec) {
        weight -= q.front().first;
        q.pop();
      }

      if (!truck.empty()) {
        if (weight + truck.front() <= l) {
          int t = truck.front();
          truck.pop();
          q.push(make_pair(t, sec));
          weight += t;
        }
      }
    }
    sec++;
  }

  cout << sec - 1;
  return 0;
}