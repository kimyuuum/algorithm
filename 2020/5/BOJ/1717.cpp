#include <iostream>
using namespace std;
const int MAX = 1000005;
int p[MAX];

int uni(int a) {
  if (p[a] == a) {
    return a;
  }
  return p[a] = uni(p[a]);
}

void add(int a, int b) {
  a = uni(a);
  b = uni(b);
  p[a] = b;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i <= n; i++) {
    p[i] = i;
  }

  while (m--) {
    int ord, a, b;
    cin >> ord >> a >> b;

    if (ord == 0) {
      add(a, b);
    } else if (ord == 1) {
      if (uni(a) == uni(b)) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }

  return 0;
}