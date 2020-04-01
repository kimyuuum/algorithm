#include <queue>
#include <string>
#include <vector>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
  int sec = 0;
  queue<pair<int, int>> q;
  int idx = 0;
  int w = 0;

  while (1) {
    sec++;
    if (q.front().second + bridge_length == sec) {
      w -= q.front().first;
      q.pop();
    }

    if (w + truck_weights[idx] <= weight) {
      if (idx == truck_weights.size() - 1) {
        sec += bridge_length;
        break;
      }
      q.push(make_pair(truck_weights[idx], sec));
      w += truck_weights[idx];
      idx++;
    }
  }

  return sec;
}