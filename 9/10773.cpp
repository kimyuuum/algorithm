//제로
#include <iostream>
#include <stack>
using namespace std;
int k, total = 0;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> k;
  stack<int> s;

  while (k--) {
    int num;
    cin >> num;

    if (num == 0) {
      total -= s.top();
      s.pop();
    } else {
      s.push(num);
      total += num;
    }
  }

  cout << total;

  return 0;
}