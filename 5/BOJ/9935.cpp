
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
char result[1000004];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string input;
  string bomb;
  cin >> input >> bomb;

  stack<pair<char, int>> s;
  int idx = 0;

  for (int i = 0; i < input.size(); i++) {
    if (input[i] == bomb[idx]) {
      idx++;
    } else if (input[i] == bomb[0]) {
      idx = 1;
    } else {
      idx = 0;
    }

    s.push(make_pair(input[i], idx));

    if (idx == bomb.size()) {
      for (int i = 0; i < bomb.size(); i++) {
        s.pop();
      }
      if (!s.empty()) {
        idx = s.top().second;
      } else {
        idx = 0;
      }
    }
  }

  if (s.empty()) {
    cout << "FRULA";
  } else {
    for (int i = s.size() - 1; i >= 0; i--) {
      result[i] = s.top().first;
      s.pop();
    }
    cout << result;
  }

  return 0;
}