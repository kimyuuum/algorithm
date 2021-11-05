#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
vector<string> v;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string input;
    cin >> input;
    if (v.empty()) {
      string newstring = input + input;
      v.push_back(newstring);
    } else {
      bool flag = false;
      for (int i = 0; i < v.size(); i++) {
        if (v[i].find(input) != string::npos) {
          if (v[i].size() / 2 == input.size()) {
            flag = true;
            break;
          }
        }
      }
      if (!flag) {
        string newstring = input + input;
        v.push_back(newstring);
      }
    }
  }

  cout << v.size();
  return 0;
}