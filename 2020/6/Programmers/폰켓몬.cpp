#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int solution(vector<int> nums) {
  int answer = 0;
  int get = nums.size() / 2;
  map<int, int> m;
  for (int i = 0; i < nums.size(); i++) {
    int number = nums[i];
    if (m.find(number) != m.end()) {
      m[number] += 1;
    } else {
      m.insert({number, 1});
    }
  }

  if (m.size() >= get) {
    answer = get;
  } else {
    answer = m.size();
  }

  return answer;
}