#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> baseball) {
  int answer = 0;
  for (int target = 123; target <= 987; target++) {
    string i = to_string(target);
    if (i[0] == i[1] || i[0] == i[2] || i[1] == i[2]) {
      continue;
    }
    if (i[0] == '0' || i[1] == '0' || i[2] == '0') {
      continue;
    }

    int correct = 0;

    for (int j = 0; j < baseball.size(); j++) {
      string num = to_string(baseball[j][0]);
      int strike = 0;
      int ball = 0;
      for (int k = 0; k < 3; k++) {
        for (int n = 0; n < 3; n++) {
          if (i[k] == num[n] && k == n) {
            strike++;
            continue;
          }
          if (i[k] == num[n] && k != n) {
            ball++;
            continue;
          }
        }
      }
      if (strike == baseball[j][1] && ball == baseball[j][2]) {
        correct++;
      }
    }
    if (correct == baseball.size()) {
      answer++;
    }
  }
  return answer;
}