#include <stack>
#include <string>
#include <vector>
using namespace std;
const int MAX = 100001;
int arr[MAX];
stack<pair<int, int>> s;

vector<int> solution(vector<int> prices) {
  vector<int> answer;
  s.push({prices[0], 0});
  for (int i = 1; i < prices.size(); i++) {
    pair<int, int> p = {prices[i], i};
    while (s.top().first > p.first) {
      arr[s.top().second] = i - s.top().second;
      s.pop();
      if (s.empty()) {
        break;
      }
    }
    s.push(p);
  }
  int size = prices.size() - 1;

  while (!s.empty()) {
    pair<int, int> p = s.top();
    int idx = p.second;
    arr[idx] = size - idx;
    s.pop();
  }

  for (int i = 0; i < prices.size(); i++) {
    answer.push_back(arr[i]);
  }
  return answer;
}
