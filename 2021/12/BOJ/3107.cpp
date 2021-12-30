#include <algorithm>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

vector<string> split(string input, char delimiter) {
  vector<string> answer;
  stringstream ss(input);
  string temp;

  while (getline(ss, temp, delimiter)) {
    answer.push_back(temp);
  }

  return answer;
}

int main() {
  string s;
  cin >> s;

  vector<string> spl = split(s, ':');
  vector<string> res;

  int zero = 0;

  if (s.find("::") != string::npos) {
    int nonZero = 0;
    for (int i = 0; i < spl.size(); i++) {
      if (spl[i].size() > 0) {
        nonZero++;
      }
    }
    zero = 8 - nonZero;
  }

  for (int i = 0; i < spl.size(); i++) {
    int size = spl[i].size();

    if (size == 0) {
      if (zero > 0) {
        while (zero--) {
          res.push_back("0000");
        }
      }
    } else if (size > 0 && size < 4) {
      int plusZero = 4 - size;
      string tmp;
      for (int j = 0; j < plusZero; j++) {
        tmp += "0";
      }
      tmp += spl[i];
      res.push_back(tmp);
    } else {
      res.push_back(spl[i]);
    }
  }

  for (int i = 0; i < res.size() - 1; i++) {
    cout << res[i] << ":";
  }

  cout << res[res.size() - 1];

  return 0;
}
