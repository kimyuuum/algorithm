#include <iostream>
#include <stack>
using namespace std;
const int MAX = 500000;
stack<pair<int, int>> s;
int arr[MAX];
int n;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int num;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> num;
    if (i == 0) {
      cout << "0 ";
    } else {
      while (!s.empty()) {
        if (s.top().second < num) {
          s.pop();
        } else {
          cout << s.top().first << " ";
          break;
        }
      }
      if (s.empty()) {
        cout << "0 ";
      }
    }
    s.push(make_pair(i + 1, num));
  }
  return 0;
}
