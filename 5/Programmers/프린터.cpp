#include <queue>
#include <string>
#include <vector>
using namespace std;
queue<pair<int, int>> q;
priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
int solution(vector<int> priorities, int location) {
  int answer = 0;
  for (int i = 0; i < priorities.size(); i++) {
    pair<int, int> p;
    p = {priorities[i], i};
    pq.push(p);
    q.push(p);
  }

  while (1) {
    if (pq.top().first != q.front().first) {
      pair<int, int> p = q.front();
      q.pop();
      q.push(p);
    } else if (pq.top().first == q.front().first) {
      answer++;
      pq.pop();
      if (location == q.front().second) {
        break;
      }
      q.pop();
    }
  }
  return answer;
}
