
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1000000;
string a, p;
int pie[MAX];

void preprocessing() {
  int j = 0;
  int k = -1;
  pie[0] = -1;

  while (j < p.size()) {
    if (k == -1 || p[j] == p[k]) {
      j++;
      k++;
      pie[j] = k;
    } else {
      k = pie[k];
    }
  }
}

int main() {
  getline(cin, a);
  getline(cin, p);

  preprocessing();
  for (int i = 0; i < p.size(); i++) {
    cout << pie[i] << " ";
  }
  return 0;
}