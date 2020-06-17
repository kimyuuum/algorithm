#include <iostream>
using namespace std;

int solution(int num) {
  int ans = 0;

  while (num != 0) {
    if (num % 2 == 0) {
      num /= 2;
    } else {
      ans++;
      num--;
    }
  }

  return ans;
}