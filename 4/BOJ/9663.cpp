
#include <iostream>
using namespace std;
const int MAX = 15;
int map[MAX];
int n, res;

bool can_pos(int line) {
  for (int i = 0; i < line; i++) {
    if (map[i] == map[line] || abs(map[i] - map[line]) == line - i) {
      return false;
    }
  }
  return true;
}

void nqueen(int line) {
  if (line == n) {
    res++;
    return;
  }
  for (int i = 0; i < n; i++) {
    map[line] = i;
    if (can_pos(line)) {
      nqueen(line + 1);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  nqueen(0);
  cout << res;
  return 0;
}

