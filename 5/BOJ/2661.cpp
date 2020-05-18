#include <iostream>
#include <vector>
using namespace std;
int n;
string ans;

void dfs(char c, int count) {
  if (n == count - 1) {
    cout << ans;
    exit(0);
  }

  ans += c;
  for (int i = 1; i <= count / 2; i++) {
    string a = ans.substr(count - i, i);
    string b = ans.substr(count - i * 2, i);

    if (a == b) {
      ans.erase(count - 1);
      return;
    }
  }

  for (int i = 1; i < 4; i++) {
    dfs(i + '0', count + 1);
  }
  
  ans.erase(count - 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  dfs(1 + '0', 1);
  return 0;
}
