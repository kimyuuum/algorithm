#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool comp(pair<string, pair<int, int>> p1, pair<string, pair<int, int>> p2) {
  if (p1.second.first == p2.second.first) {
    if (p1.second.second == p2.second.second) {
      return p1.first < p2.first;
    }
    return p1.second.second > p2.second.second;
  }

  return p1.second.first > p2.second.first;
}

vector<string> solution(vector<string> company_names,
                        vector<vector<int>> scores) {
  vector<string> answer;
  vector<pair<string, pair<int, int>>> v;
  for (int i = 0; i < company_names.size(); i++) {
    string name = company_names[i];
    int sum = 0;
    int cnt = 0;
    for (int j = 0; j < scores[i].size(); j++) {
      sum += scores[i][j];
      if (scores[i][j] >= 80) {
        cnt++;
      }
    }

    v.push_back(make_pair(name, make_pair(cnt, sum)));
  }

  sort(v.begin(), v.end(), comp);
  for (int i = 0; i < v.size(); i++) {
    answer.push_back(v[i].first);
  }
  return answer;
}
