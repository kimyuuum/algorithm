#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// vector<vector<int>> jobs = {{0, 3}, {1, 9}, {2, 6}};
vector<vector<int>> jobs = {{0, 3}, {4, 4}, {5, 3}, {4, 1}};
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    pq;

int main() {
  sort(jobs.begin(), jobs.end());
  int jobSize = jobs.size();
  int curT = 0, idx = 0, answer = 0;

  while (jobSize > 0) {
    while (idx < jobs.size() && jobs[idx][0] <= curT) {
      pq.push(make_pair(jobs[idx][1], jobs[idx][0]));
      idx++;
    }
    if (!pq.empty()) {
      int start = pq.top().second;
      int work = pq.top().first;
      if (start <= curT) {
        pq.pop();
        cout << start << " " << work << " " << curT << endl;
        jobSize--;

        curT += work;
        answer += (curT - start);
      }
    } else {
      curT = jobs[idx][0];
    }
  }

  cout << answer / jobs.size();
  return 0;
}