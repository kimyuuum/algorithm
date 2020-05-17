
#include <iostream>
using namespace std;
struct TRIE {
  bool finish;
  TRIE* node[10];
  TRIE() {
    finish = false;
    for (int i = 0; i < 11; i++) {
      node[i] = 0;
    }
  }
  void insert(char*);
  bool find(char*);
};

void TRIE::insert(char* str) {
  if (*str == '\0') {
    finish = true;
  } else {
    int cur = *str - '0';
    if (node[cur] == NULL) {
      node[cur] = new TRIE();
    }
    node[cur]->insert(str + 1);
  }
}

bool TRIE::find(char* str) {
  if (*str == '\0') {
    return false;
  }
  if (finish) {
    return true;
  }
  int cur = *str - '0';

  return node[cur]->find(str + 1);
}

int main() {
  int testcase;
  cin >> testcase;
  while (testcase--) {
    char arr[51][11];
    int n;
    bool flag = false;
    cin >> n;
    TRIE* trie = new TRIE();
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
      trie->insert(arr[i]);
    }
    for (int i = 0; i < n; i++) {
      if (trie->find(arr[i])) {
        flag = true;
      }
    }
    if (flag) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
  return 0;
}