#include <string>
#include <vector>
using namespace std;

struct TRIE {
  bool finish;
  TRIE* node[10];
  TRIE() {
    finish = false;
    for (int i = 0; i < 10; i++) {
      node[i] = 0;
    }
  }

  bool insert(const char* str) {
    if (*str == '\0') {
      finish = true;
      return true;
    } else {
      if (finish) {
        return false;
      }
      int cur = *str - '0';
      if (node[cur] == 0) {
        node[cur] = new TRIE();
      } else if (node[cur] != 0 && *(str + 1) == '\0') {
        return false;
      }
      return node[cur]->insert(str + 1);
    }
  }
};

bool solution(vector<string> phone_book) {
  bool answer = true;
  TRIE trie;
  for (int i = 0; i < phone_book.size(); i++) {
    answer = trie.insert(phone_book[i].c_str());
    if (!answer) {
      return false;
    }
  }

  return answer;
}