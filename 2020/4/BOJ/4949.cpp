
#include <cstring>
#include <iostream>
#include <stack>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string input;
  while (1) {
    stack<char> s;
    bool flag = true;
    getline(cin, input);
    if (input.size() == 1 && input[0] == '.') {
      break;
    }

    for (int i = 0; i < input.size(); i++) {
      if (input[i] == '(' || input[i] == '[') {
        s.push(input[i]);
      }
      if (input[i] == ')') {
        if (!s.empty() && s.top() == '(') {
          s.pop();
        } else {
          flag = false;
          break;
        }

      } else if (input[i] == ']') {
        if (!s.empty() && s.top() == '[') {
          s.pop();
        } else {
          flag = false;
          break;
        }
      }
    }

    if (flag && s.empty()) {
      cout << "yes\n";
    } else {
      cout << "no\n";
    }
  }

  return 0;
}
