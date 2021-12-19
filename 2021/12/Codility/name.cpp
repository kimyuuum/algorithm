
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
string s = "LILLYBILLYBOO";
vector<string> v = {"LILLY", "BILL", "MARIA"};
int alpha[26] = {
    0,
};
int cnt[26] = {
    0,
};

int main() {
  int result = 0;

  for (int i = 0; i < s.size(); i++) {
    int alCode = s[i] - 65;
    alpha[alCode]++;
  }

  for (int idx = 0; idx < v.size(); idx++) {
    int possible = 987654321;
    memset(cnt, 0, sizeof(cnt));
    string name = v[idx];

    for (int i = 0; i < name.size(); i++) {
      int alCnt = name[i] - 65;
      cnt[alCnt]++;
    }

    for (int i = 0; i < 26; i++) {
      if (cnt[i] != 0) {
        if (possible >= alpha[i] / cnt[i]) {
          possible = alpha[i] / cnt[i];
        }
      }
    }

    if (result < possible) {
      result = possible;
    }
  }

  cout << result;

  return 0;
}