#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
const long MAX = 100000001;
bool cnt[MAX] = {
    false,
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  long a, p;
  cin >> a >> p;

  long sameNum = 0;
  vector<int> v;
  v.push_back(a);
  cnt[a] = true;

  while (1) {
    long num = v.back();
    long nextNum = 0;

    while (num != 0) {
      nextNum += pow(num % 10, p);
      num /= 10;
    }

    if (cnt[nextNum]) {
      sameNum = nextNum;
      break;
    }

    v.push_back(nextNum);
    cnt[nextNum] = true;
  }

  int result = 0;

  for (int i = 0; i < v.size(); i++) {
    if (v[i] == sameNum) {
      break;
    }
    result++;
  }

  cout << result;

  return 0;
}