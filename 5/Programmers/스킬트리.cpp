#include <stack>
#include <string>
#include <vector>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
  int answer = 0;
  for (int j = 0; j < skill_trees.size(); j++) {
    string input = skill_trees[j];
    stack<char> s;
    bool flag = false;
    for (int i = 0; i < input.size(); i++) {
      if (skill.find(input[i]) != string::npos) {
        int idx = skill.find(input[i]);
        if (idx == 0) {
          s.push(input[i]);
        } else {
          if (s.empty()) {
            flag = true;
            break;
          } else {
            if (s.top() != skill[idx - 1]) {
              flag = true;
              break;
            } else {
              s.push(input[i]);
            }
          }
        }
      }
    }
    if (!flag) {
      answer++;
    }
  }
  return answer;
}