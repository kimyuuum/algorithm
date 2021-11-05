
#include <iostream>
#include <stack>
using namespace std;
stack<int> s;
long long res;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, num;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> num;
    if (i == 0) {
      s.push(num);
    } else {
      while (!s.empty()) {
        if (s.top() <= num) {
          s.pop();
        } else {
          break;
        }
      }
      res += s.size();
      s.push(num);
    }
  }
  cout << res;
  return 0;
}