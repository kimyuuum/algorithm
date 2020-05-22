#include <iostream>
#include <map>
using namespace std;
const int MAX = 100001;
int m, n;
string arr[MAX];
map<string, int> mp;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    string a;
    cin >> a;
    arr[i] = a;
    mp.insert(make_pair(a, i));
  }

  while (m--) {
    string input;
    cin >> input;
    if (input[0] >= 'A' && input[0] <= 'Z') {
      cout << mp.find(input)->second << "\n";
    } else {
      int idx = atoi(input.c_str());
      cout << arr[idx] << "\n";
    }
  }

  return 0;
}