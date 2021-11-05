#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
  int answer = 0;
  int left = 0;
  int right = distance;
  sort(rocks.begin(), rocks.end());
  rocks.push_back(distance);

  while (left <= right) {
    int mid = (left + right) / 2;
    int cnt = 0;
    int prev = 0;  //돌의값이니까 1번째 0 맞음.

    for (int i = 0; i < rocks.size(); i++) {
      if (rocks[i] - prev < mid) {
        cnt++;
      } else {
        prev = rocks[i];
      }
    }

    if (cnt > n) {
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