#include <string>
#include <vector>
using namespace std;
vector<int> numbers;
int target = 0;
int answer = 0;

void dfs(int curX, int cnt, int res) {
  if (cnt == numbers.size()) {
    if (res == target) {
      answer++;
    }
    return;
  }

  for (int i = curX + 1; i < numbers.size(); i++) {
    int nextX = numbers[i];
    int minusX = numbers[i] * -1;

    dfs(i, cnt + 1, res + nextX);
    dfs(i, cnt + 1, res + minusX);
  }

  return;
}

int solution(vector<int> number, int targets) {
  target = targets;

  for (int i = 0; i < number.size(); i++) {
    numbers.push_back(number[i]);
  }

  dfs(0, 1, number[0]);
  dfs(0, 1, number[0] * -1);

  return answer;
}