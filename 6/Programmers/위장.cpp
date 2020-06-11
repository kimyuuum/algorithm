#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
vector<vector<string>> clothes = {{"yellow_hat", "headgear"},
                                  {"blue_sunglasses", "eyewear"},
                                  {"green_turban", "headgear"}};

int main() {
  int answer = 1;
  map<string, int> m;

  for (int i = 0; i < clothes.size(); i++) {
    map<string, int>::iterator it;
    string key = clothes[i][1];
    it = m.find(key);
    if (it == m.end()) {
      m.insert({key, 1});
    } else {
      int cnt = it->second;
      cnt++;
      m.at(key) = cnt;
    }
  }

  map<string, int>::iterator iter;
  vector<int> v;
  for (iter = m.begin(); iter != m.end(); ++iter) {
    v.push_back((iter->second) + 1);
  }

  for (int i = 0; i < v.size(); i++) {
    answer *= v[i];
  }
  answer--;
  cout << answer;
  return 0;
}
