#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
  vector<int> answer;
  int x = 1;
  int y = 1;
  while (x <= y) {
    if (yellow % x == 0) {
      y = yellow / x;
    } else {
      x++;
      continue;
    }
    int res = (2 * x) + (2 * y) + 4;
    ;
    if (res == brown) {
      break;
    }
    x++;
  }
  answer.push_back(y + 2);
  answer.push_back(x + 2);
  return answer;
}