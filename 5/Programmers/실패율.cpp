#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool comp(pair<double, int> p1, pair<double, int> p2) {
  if (p1.first == p2.first) {
    return p1.second < p2.second;
  }
  return p1.first > p2.first;
}

vector<int> solution(int N, vector<int> stages) {
  vector<int> answer;
  vector<pair<double, int>> v;

  sort(stages.begin(), stages.end());
  int stage = 1;
  while (stage <= N) {
    int c = 0;
    int clear = 0;
    for (int i = 0; i < stages.size(); i++) {
      if (stage == stages[i]) {
        c++;
      }
      if (stage <= stages[i]) {
        clear++;
      }
    }
    double rate = 0;
    if (clear != 0) {
      rate = (double)c / (clear + c);
    }
    v.push_back(make_pair(rate, stage));
    stage++;
  }

  sort(v.begin(), v.end(), comp);
  for (int i = 0; i < v.size(); i++) {
    answer.push_back(v[i].second);
  }
  return answer;
}