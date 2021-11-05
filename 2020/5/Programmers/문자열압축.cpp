#include <string>
#include <vector>
using namespace std;

int solution(string s) {
  int answer = s.size();
  int count = 1;
  while (count <= s.size() / 2) {
    int idx = 0;
    string temp = "";
    while (idx <= s.size() - count) {
      int num = 1;
      string a = s.substr(idx, count);
      for (int i = idx + count; i <= s.size() - count; i += count) {
        string b = s.substr(i, count);
        if (a == b) {
          num++;
        } else {
          break;
        }
      }
      if (num != 1) {
        temp += to_string(num);
        temp += a;
        idx += (count * num);
      } else {
        temp += a;
        idx += count;
      }
    }
    if (idx != s.size()) {
      temp += s.substr(idx, s.size() - idx);
    }
    if (answer > temp.size()) {
      answer = temp.size();
    }
    count++;
  }
  return answer;
}