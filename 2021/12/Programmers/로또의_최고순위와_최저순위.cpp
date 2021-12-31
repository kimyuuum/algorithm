#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int MAX = 46;
int cnt[MAX] = {
    0,
};

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
  vector<int> answer;
  int zero = 0;
  for (int i = 0; i < lottos.size(); i++) {
    int number = lottos[i];
    if (number == 0) {
      zero++;
      continue;
    }
    cnt[number]++;
  }

  int match = 0;
  for (int i = 0; i < win_nums.size(); i++) {
    int num = win_nums[i];
    if (cnt[num] != 0) {
      match++;
    }
  }

  int high = 7 - (match + zero);
  int low = 7 - match;

  if (high >= 6) {
    high = 6;
  }
  if (low >= 6) {
    low = 6;
  }
  answer.push_back(high);
  answer.push_back(low);

  return answer;
}