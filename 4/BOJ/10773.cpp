
#include <iostream>
#include <stack>
using namespace std;
long long res;
int n;
stack<int> s;

int main() {
  int num;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> num;
    if (num == 0) {
      res -= s.top();
      s.pop();
    } else {
      s.push(num);
      res += num;
    }
  }

  cout << res;
  return 0;
}