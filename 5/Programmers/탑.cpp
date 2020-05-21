#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
stack<pair<int, int>> s;

vector<int> solution(vector<int> heights) {
  vector<int> answer;
  answer.push_back(0);
  s.push({heights[0], 1});
  for (int i = 1; i < heights.size(); i++) {
    int height = heights[i];
    while (!s.empty()) {
      if (s.top().first <= height) {
        s.pop();
      } else {
        answer.push_back(s.top().second);
        break;
      }
    }
    if (s.empty()) {
      answer.push_back(0);
    }
    s.push(make_pair(height, i + 1));
  }
  return answer;
}

int main() {
  vector<int> v = {7, 6, 5, 4, 3, 2, 1};
  vector<int> res = solution(v);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
}