#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 30003;
int char_to_index(char c) { return c - 'a'; }

struct Trie {
  bool is_terminal;
  Trie* next[26];

  Trie() : is_terminal(false) { memset(next, 0, sizeof(next)); }

  ~Trie() {
    for (int i = 0; i < 26; ++i) {
      if (next[i]) {
        delete next[i];
      }
    }
  }

  void insert(const char* key) {
    if (*key == '\0') {
      is_terminal = true;
    } else {
      int index = char_to_index(*key);
      if (next[index] == 0) next[index] = new Trie();
      next[index]->insert(key + 1);
    }
  }

  bool find(const char* key) {
    if (*key == '\0') return true;

    if (is_terminal) return false;

    int index = char_to_index(*key);
    return next[index]->find(key + 1);
  }
};

int main() {
  vector<string> S = {"zzzz", "ferz", "zdsr", "fgtd"};
  Trie* root = new Trie();
  char arr[MAX][26];
  int idx = 0;

  for (int i = 0; i < S.size(); i++) {
    root->insert(S[i].c_str());
  }

  bool fin = true;

  for (int i = 0; i < S.size(); i++) {
    if (root->find(S[i].c_str()) == false) {
      fin = false;
      cout << S[i] << endl;
      break;
    }
  }
  delete root;
  cout << fin;

  return 0;
}