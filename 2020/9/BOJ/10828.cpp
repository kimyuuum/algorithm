#include <cstring>
#include <iostream>
#include <stack>
using namespace std;
int n;

int main() {
  cin >> n;
  stack<int> s;

  while (n--) {
    string command;
    int num;
    cin >> command;

    if (command == "push") {
      cin >> num;
      s.push(num);
    } else if (command == "pop") {
      if (s.empty()) {
        cout << "-1" << endl;
      } else {
        cout << s.top() << endl;
        s.pop();
      }
    } else if (command == "size") {
      cout << s.size() << endl;
    } else if (command == "empty") {
      if (s.empty()) {
        cout << "1" << endl;
      } else {
        cout << "0" << endl;
      }
    } else if (command == "top") {
      if (s.empty()) {
        cout << "-1" << endl;
      } else {
        cout << s.top() << endl;
      }
    }
  }

  return 0;
}