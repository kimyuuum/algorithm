
#include <cstring>
#include <iostream>
#include <stack>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int testcase = 1;
  while (1) {
    string input;
    stack<char> s;
    int cnt = 0;
    cin >> input;
    if (input[0] == '-') {
      break;
    }
    for (int i = 0; i < input.size(); i++) {
      if (input[i] == '{') {
        s.push(input[i]);
      } else if (input[i] == '}') {
        if (s.empty()) {
          s.push('{');
          cnt++;
        } else {
          if (s.top() == '{') {
            s.pop();
          }
        }
      }
    }

    while (!s.empty()) {
      s.pop();
      s.pop();
      cnt++;
    }

    cout << testcase << ". " << cnt << "\n";
    testcase++;
  }

  return 0;
}