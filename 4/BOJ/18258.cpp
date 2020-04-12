
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
int n;
queue<int> q;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  string c;
  while (n--) {
    cin >> c;
    if (c == "push") {
      int num;
      cin >> num;
      q.push(num);
    } else if (c == "pop") {
      if (q.empty()) {
        cout << "-1\n";
      } else {
        int num = q.front();
        cout << num << "\n";
        q.pop();
      }
    } else if (c == "size") {
      cout << q.size() << "\n";
    } else if (c == "empty") {
      if (q.empty()) {
        cout << "1\n";
      } else {
        cout << "0\n";
      }
    } else if (c == "front") {
      if (q.empty()) {
        cout << "-1\n";
      } else {
        cout << q.front() << "\n";
      }
    } else if (c == "back") {
      if (q.empty()) {
        cout << "-1\n";
      } else {
        cout << q.back() << "\n";
      }
    }
  }
  return 0;
}