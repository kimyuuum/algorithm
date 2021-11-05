
#include <iostream>
#include <set>
using namespace std;
const int MAX = 1001;
char map[MAX][MAX];
int r, c;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> r >> c;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> map[i][j];
    }
  }

  int left = 1;
  int right = r - 1;
  int count = 0;

  while (left <= right) {
    bool flag = true;
    int mid = (left + right) / 2;
    set<string> s;
    for (int n = 0; n < c; n++) {
      string input;
      for (int i = mid; i < r; i++) {
        input += map[i][n];
      }
      if (!s.insert(input).second) {
        flag = false;
        break;
      }
    }
    if (!flag) {
      right = mid - 1;
    } else {
      if (count < mid) {
        count = mid;
      }
      left = mid + 1;
    }
  }

  cout << count;
  return 0;
}
