#include <string>
#include <vector>

using namespace std;

int solution(int n) {
  int answer = 0;
  int left = 1;
  int right = 1;

  int sum = 1;

  while (left <= n) {
    if (sum == n) {
      answer++;
      right++;
      sum += right;
    } else if (sum < n) {
      right++;
      sum += right;
    } else {
      sum -= left;
      left++;
      if (left > right) {
        right = left;
        sum = left;
      }
    }
  }

  return answer;
}