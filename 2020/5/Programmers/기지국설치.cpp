#include <iostream>
#include <vector>
using namespace std;

int calc(int left, int right, int w) {
  int cnt = 0;
  int len = right - left + 1;
  int range = (2 * w) + 1;

  while (cnt * range < len) {
    cnt++;
  }

  return cnt;
}

int solution(int n, vector<int> stations, int w) {
  int answer = 0;
  if (stations[0] - w - 1 >= 1) {
    answer += calc(1, stations[0] - w - 1, w);
  }
  for (int i = 1; i < stations.size(); i++) {
    answer += calc(stations[i - 1] + w + 1, stations[i] - w - 1, w);
  }
  if (stations.back() + w + 1 <= n) {
    answer += calc(stations.back() + w + 1, n, w);
  }

  return answer;
}