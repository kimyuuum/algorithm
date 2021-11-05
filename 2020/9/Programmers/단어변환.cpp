
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 55;
vector<string> words = {"hot", "dot", "dog", "lot", "log"};
string beg = "hit";
string target = "cog";
bool visited[MAX];
int res = 987654321;

void dfs(string word, int cnt) {
  if (word == target) {
    if (res > cnt) {
      res = cnt;
    }
    return;
  }

  for (int i = 0; i < words.size(); i++) {
    if (visited[i]) {
      continue;
    }
    string next = words[i];
    int diff = 0;
    for (int j = 0; j < word.size(); j++) {
      if (word[j] - next[j] != 0) {
        diff++;
      }
    }
    if (diff == 1) {
      visited[i] = true;
      dfs(next, cnt + 1);
      visited[i] = false;
    }
  }
}

int main() {
  dfs(beg, 0);
  if (res == 987654321) {
    cout << 0;
  } else {
    cout << res;
  }
  return 0;
}