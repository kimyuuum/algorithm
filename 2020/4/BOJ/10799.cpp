
#include <cstring>
#include <iostream>
#include <stack>
using namespace std;

int main() {
  string input;
  stack<char> s;
  int res = 0;
  cin >> input;
  for (int i = 0; i < input.size(); i++) {
    if (input[i] == '(') {
      s.push(input[i]);
    } else if (input[i] == ')') {
      if (input[i - 1] == '(') {
        s.pop();
        res += s.size();
      } else {
        s.pop();
        res++;
      }
    }
  }

  cout << res;
}