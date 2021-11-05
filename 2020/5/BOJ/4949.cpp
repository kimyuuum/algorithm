#include <iostream>
#include <stack>
using namespace std;

int main() {
  string input;
  while (1) {
    stack<char> s;
    getline(cin, input);
    bool flag = false;
    if (input.size() == 1 && input == ".") {
      break;
    } else {
      for (int i = 0; i < input.size(); i++) {
        if (input[i] == '(') {
          s.push('(');
        } else if (input[i] == '[') {
          s.push('[');
        } else if (input[i] == ')') {
          if (s.empty()) {
            flag = true;
            break;
          } else if (s.top() != '(') {
            flag = true;
            break;
          } else {
            s.pop();
          }
        } else if (input[i] == ']') {
          if (s.empty()) {
            flag = true;
            break;
          } else if (s.top() != '[') {
            flag = true;
            break;
          } else {
            s.pop();
          }
        }
      }
    }
    if (flag || !s.empty()) {
      cout << "no\n";
    } else {
      cout << "yes\n";
    }
  }

  return 0;
}