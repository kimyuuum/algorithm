#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stack>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string input;
  stack<string> s;
  cin >> input;
  bool flag = true;

  for (int i = 0; i < input.size(); i++) {
    if (input[i] == '(') {
      s.push("(");
    } else if (input[i] == '[') {
      s.push("[");
    } else {
      if (s.empty()) {
        flag = false;
        break;
      } else if (input[i] == ')') {
        if (s.top() == "(") {
          s.pop();
          s.push("2");
        } else {
          int tmp = 0;
          while (!s.empty()) {
            string top = s.top();
            if (top == "[") {
              flag = false;
              break;
            } else if (top == "(") {
              s.pop();
              tmp *= 2;
              s.push(to_string(tmp));
              break;
            } else {
              tmp += atoi(top.c_str());
              s.pop();
            }
          }
        }
      } else if (input[i] == ']') {
        if (s.top() == "[") {
          s.pop();
          s.push("3");
        } else {
          int tmp = 0;
          while (!s.empty()) {
            string top = s.top();
            if (top == "(") {
              flag = false;
              break;
            } else if (top == "[") {
              s.pop();
              tmp *= 3;
              s.push(to_string(tmp));
              break;
            } else {
              tmp += atoi(top.c_str());
              s.pop();
            }
          }
        }
      }
    }
  }
  int res = 0;
  if (!flag) {
    cout << "0";
  } else {
    while (!s.empty()) {
      if (s.top() == "(" || s.top() == "[" || s.top() == ")" ||
          s.top() == "]") {
        cout << "0";
        return 0;
      } else {
        res += atoi(s.top().c_str());
        s.pop();
      }
    }
    cout << res;
  }
  return 0;
}