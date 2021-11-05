
#include <iostream>
using namespace std;
char arr[26][2];
int n;

void preorder(char al) {
  cout << al;
  int idx = al - 65;

  if (arr[idx][0] != '.') {
    preorder(arr[idx][0]);
  }
  if (arr[idx][1] != '.') {
    preorder(arr[idx][1]);
  }
}

void inorder(char al) {
  int idx = al - 65;
  if (arr[idx][0] != '.') {
    inorder(arr[idx][0]);
  }
  cout << al;
  if (arr[idx][1] != '.') {
    inorder(arr[idx][1]);
  }
}

void postorder(char al) {
  int idx = al - 65;

  if (arr[idx][0] != '.') {
    postorder(arr[idx][0]);
  }

  if (arr[idx][1] != '.') {
    postorder(arr[idx][1]);
  }

  cout << al;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    char root, l, r;
    cin >> root >> l >> r;
    arr[root - 'A'][0] = l;
    arr[root - 'A'][1] = r;
  }
  preorder('A');
  cout << "\n";
  inorder('A');
  cout << "\n";
  postorder('A');
}