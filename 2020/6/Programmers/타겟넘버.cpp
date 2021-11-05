#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool visited[20] = {
    false,
};
vector<int> number;
int res;
int answer;

void dfs(int num, int idx, int size) {
  if (size == number.size() && res == num) {
    answer++;
    return;
  }

  for (int i = 0; i < 2; i++) {
    for (int j = idx + 1; j < number.size(); j++) {
      if (!visited[j]) {
        int n = number[j];
        if (i == 0) {
          n *= -1;
        }
        num += n;
        visited[j] = true;
        dfs(num, j, size + 1);
        visited[j] = false;
        num -= n;
      }
    }
  }
}

int solution(vector<int> numbers, int target) {
  number = numbers;
  res = target;
  answer = 0;

  for (int i = 0; i < 2; i++) {
    int n = numbers[0];
    if (i == 0) {
      n *= -1;
    }
    visited[0] = true;
    dfs(n, 0, 1);
    visited[0] = false;
  }
  return answer;
}