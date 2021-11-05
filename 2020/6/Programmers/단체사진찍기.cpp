#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

int solution(int n, vector<string> input) {
  int answer = 0;

  vector<char> friends = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};

  do {
    bool flag = true;

    for (int i = 0; i < input.size(); i++) {
      char a = input[i][0];
      char b = input[i][2];
      char op = input[i][3];
      int val = input[i][4] - '0';
      int aidx = 0;
      int bidx = 0;

      for (int j = 0; j < friends.size(); j++) {
        if (friends[j] == a) {
          aidx = j;
        } else if (friends[j] == b) {
          bidx = j;
        }
      }

      int discount = abs(aidx - bidx) - 1;

      if (op == '=') {
        if (discount != val) {
          flag = false;
          break;
        }
      } else if (op == '>') {
        if (discount <= val) {
          flag = false;
          break;
        }
      } else if (op == '<') {
        if (discount >= val) {
          flag = false;
          break;
        }
      }
    }

    if (flag) {
      answer++;
    }

  } while (next_permutation(friends.begin(), friends.end()));
  return answer;
}