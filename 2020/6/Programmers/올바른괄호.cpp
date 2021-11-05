#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool solution(string a) {
  bool answer = true;
  stack<char> s;

  for (int i = 0; i < a.size(); i++) {
    char input = a[i];
    if (input == '(') {
      s.push(input);
    } else {
      if (s.empty()) {
        answer = false;
        break;
      } else {
        s.pop();
      }
    }
  }

  if (!s.empty()) {
    answer = false;
  }

  return answer;
}