
#include <cstring>
#include <iostream>
using namespace std;
const int MAX = 26;
char node[MAX][2];
bool visited[MAX];
int n;

string res = "";

void preTraverse(char al) {
  if (!visited[al - 65]) {
    res += al;
    visited[al - 65] = true;
  }
  if (node[al - 65][0] != '.') {
    preTraverse(node[al - 65][0]);
  }
  if (node[al - 65][1] != '.') {
    preTraverse(node[al - 65][1]);
  }
}

void inTraverse(char al) {
  if (node[al - 65][0] != '.') {
    inTraverse(node[al - 65][0]);
  }
  if (!visited[al - 65]) {
    res += al;
    visited[al - 65] = true;
  }
  if (node[al - 65][1] != '.') {
    inTraverse(node[al - 65][1]);
  }
}

void postTraverse(char al) {
  if (node[al - 65][0] != '.') {
    postTraverse(node[al - 65][0]);
  }
  if (node[al - 65][1] != '.') {
    postTraverse(node[al - 65][1]);
  }
  if (!visited[al - 65]) {
    res += al;
    visited[al - 65] = true;
  }
}

int main() {
  cin >> n;
  char m, l, r;
  for (int i = 0; i < n; i++) {
    cin >> m >> l >> r;
    node[m - 65][0] = l;
    node[m - 65][1] = r;
  }

  preTraverse('A');
  cout << res << "\n";
  memset(visited, false, sizeof(visited));
  res = "";
  inTraverse('A');
  cout << res << "\n";
  memset(visited, false, sizeof(visited));
  res = "";
  postTraverse('A');
  cout << res << "\n";

  return 0;
}