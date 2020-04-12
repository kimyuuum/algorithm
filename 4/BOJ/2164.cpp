
#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    q.push(i);
  }
  while (n != 1) {
    q.pop();
    if (q.size() == 1) {
      break;
    }
    int num = q.front();
    q.pop();
    q.push(num);
  }
  cout << q.front();

  return 0;
}