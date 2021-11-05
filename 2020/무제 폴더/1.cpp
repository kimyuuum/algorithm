
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> deposit) {
  vector<int> answer;
  stack<int> s;
  for (int i = 0; i < deposit.size(); i++) {
    int money = deposit[i];
    if (money > 0) {
      s.push(money);
    } else {
      int top;
      if (abs(money) <= s.top()) {
        top = s.top();
        s.pop();
        top = top + money;
        if (top > 0) {
          s.push(top);
        }
      } else {
        //클 경우 머니가 계속 음수임
        while (money < 0) {
          int top = s.top();
          s.pop();
          money += top;
        }
        if (money > 0) {
          s.push(money);
        }
      }
    }
  }

  while (!s.empty()) {
    answer.push_back(s.top());
    s.pop();
  }

  for (int i = 0; i < answer.size(); i++) {
    cout << answer[i] << " ";
  }
  return answer;
}

int main() {
  vector<int> v = {500, 1000, 2000, -1000, -1500, 500};
  solution(v);
  return 0;
}