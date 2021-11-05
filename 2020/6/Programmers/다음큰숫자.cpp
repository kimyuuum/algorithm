#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(int number) {
  int onecnt = 0;
  int n = number;
  while (n != 0) {
    int num = n % 2;
    if (num == 1) {
      onecnt++;
    }
    n /= 2;
  }

  int answer = number + 1;
  while (1) {
    int cnt = 0;
    int target = answer;
    while (target != 0) {
      int num = target % 2;
      if (num == 1) {
        cnt++;
      }
      target /= 2;
    }
    if (cnt == onecnt) {
      break;
    } else {
      answer++;
    }
  }
  return answer;
}