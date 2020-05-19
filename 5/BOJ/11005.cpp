#include <iostream>
#include <vector>
using namespace std;
vector<char> v;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int a, b;
  cin >> a >> b;
  while (a != 0) {
    int num = a % b;
    char c;
    if (num >= 10) {
      c = char(num + 55);
    } else {
      c = char(num + 48);
    }
    v.push_back(c);
    a /= b;
  }

  for (int i = v.size() - 1; i >= 0; i--) {
    cout << v[i];
  }
}