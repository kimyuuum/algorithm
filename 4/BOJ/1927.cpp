
#include <iostream>
#include <queue>
using namespace std;
const int MAX = 100000;
priority_queue<int, vector<int>, greater<int>> heap;
int n;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  int num;

  while (n--) {
    cin >> num;

    if (num == 0) {
      if (heap.empty()) {
        cout << "0\n";
      } else {
        cout << heap.top() << "\n";
        heap.pop();
      }
    } else {
      heap.push(num);
    }
  }
  return 0;
}
