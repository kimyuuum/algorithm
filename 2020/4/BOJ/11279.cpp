
#include <iostream>
#include <queue>
using namespace std;
int n;
priority_queue<int, vector<int>, less<int>> heap;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int num;
  cin >> n;
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