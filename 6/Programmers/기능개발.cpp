#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
  vector<int> answer;
  queue<int> q;
  for (int i = 0; i < progresses.size(); i++) {
    q.push(i);
  }
  while (!q.empty()) {
    int count = 1;
    int idx = q.front();
    q.pop();
    int day = 0;
    if ((100 - progresses[idx]) % speeds[idx] == 0) {
      day = (100 - progresses[idx]) / speeds[idx];
    } else {
      day = (100 - progresses[idx]) / speeds[idx] + 1;
    }

    bool isPop = false;
    while (!q.empty()) {
      int nidx = q.front();
      if (progresses[nidx] + (speeds[nidx] * day) >= 100) {
        isPop = true;
        count++;
        q.pop();
      } else {
        isPop = false;
      }
      if (!isPop) {
        break;
      }
    }
    answer.push_back(count);
  }
  return answer;
}