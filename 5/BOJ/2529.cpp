#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
vector<char> op;
bool visited[10];
int k;
long long rmax = 0;
long long rmin = 9876543210;
vector<int> v;
string ans1 = "";
void dfs(int idx, int count) {
  if (count == k + 1) {
    for (int i = 0; i < v.size() - 1; i++) {
      if (op[i] == '>') {
        if (v[i] < v[i + 1]) {
          return;
        }
      } else if (op[i] == '<') {
        if (v[i] > v[i + 1]) {
          return;
        }
      }
    }
    long long num = 0;
    for (int i = 0; i < v.size(); i++) {
      num += (long long)v[i] * powl(10, v.size() - (i + 1));
    }
    if (num > rmax) {
      rmax = num;
    }
    if (num < rmin) {
      rmin = num;
    }
    return;
  }

  for (int i = 0; i < 10; i++) {
    if (!visited[i]) {
      visited[i] = true;
      v.push_back(i);
      dfs(i, count + 1);
      visited[i] = false;
      v.pop_back();
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> k;

  for (int i = 0; i < k; i++) {
    char input;
    cin >> input;
    op.push_back(input);
  }

  for (int i = 0; i < 10; i++) {
    visited[i] = true;
    v.push_back(i);
    dfs(i, 1);
    visited[i] = false;
    v.pop_back();
  }
  string ans1 = "";
  string ans2 = "";
  ans1 = to_string(rmax);
  ans2 = to_string(rmin);

  if (ans1.length() != k + 1) {
    for (int i = 0; i < (k + 1) - ans1.length(); i++) {
      ans1 = "0" + ans1;
    }
  }

  if (ans2.length() != k + 1) {
    for (int i = 0; i < (k + 1) - ans2.length(); i++) {
      ans2 = "0" + ans2;
    }
  }
  cout << ans1 << "\n" << ans2;
  return 0;
}