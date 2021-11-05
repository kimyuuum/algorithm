#include <cmath>
#include <iostream>
using namespace std;
long long n;

void hanoi(int num, int start, int by, int to) {
  if (num == 1) {
    cout << start << " " << to << "\n";
  } else {
    hanoi(num - 1, start, to, by);
    cout << start << " " << to << "\n";
    hanoi(num - 1, by, start, to);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  cout << (int)pow(2, n) - 1 << "\n";
  hanoi(n, 1, 2, 3);

  return 0;
}
