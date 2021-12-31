#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int solution(vector<int> scoville, int K) {
  int answer = 0;
  priority_queue<int, vector<int>, greater<int>> pq;

  for (int i = 0; i < scoville.size(); i++) {
    pq.push(scoville[i]);
  }

  while (pq.size() >= 2) {
    int first = pq.top();
    if (first >= K) {
      break;
    }
    pq.pop();
    int second = pq.top();
    pq.pop();
    int mixed = first + (second * 2);
    pq.push(mixed);
    answer++;
  }

  if (pq.size() == 1 && pq.top() < K) {
    return -1;
  }

  return answer;
}