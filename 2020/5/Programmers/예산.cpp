#include <string>
#include <vector>
using namespace std;

int solution(vector<int> budgets, int M) {
  int answer = 0;
  int left = 0;
  int right = *max_element(budgets.begin(), budgets.end());

  while (left <= right) {
    int cnt = 0;
    int mid = (left + right) / 2;
    for (int i = 0; i < budgets.size(); i++) {
      if (budgets[i] <= mid) {
        cnt += budgets[i];
      } else {
        cnt += mid;
      }
    }
    if (cnt > M) {
      right = mid - 1;
    } else {
      if (answer <= mid) {
        answer = mid;
      }
      left = mid + 1;
    }
  }

  return answer;
}

