
#include <cstring>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
vector<string> genres = {"classic", "pop", "classic", "classic", "pop"};
vector<int> plays = {500, 600, 150, 800, 2500};

bool comp1(pair<string, int> v1, pair<string, int> v2) {
  return v1.second > v2.second;
}

bool comp2(pair<int, int> v1, pair<int, int> v2) {
  if (v1.first == v2.first) {
    return v1.second < v2.second;
  }
  return v1.first > v2.first;
}

int main() {
  vector<int> answer;
  multimap<string, pair<int, int>> m;
  map<string, int> cnt;

  for (int i = 0; i < genres.size(); i++) {
    string genre = genres[i];
    int play = plays[i];

    m.insert({genre, {play, i}});

    if (cnt.find(genre) != cnt.end()) {
      int value = cnt.find(genre)->second;
      value += play;
      cnt[genre] = value;
    } else {
      cnt.insert({genre, play});
    }
  }

  map<string, int>::iterator it;
  vector<pair<string, int>> v;

  for (it = cnt.begin(); it != cnt.end(); it++) {
    v.emplace_back(make_pair(it->first, it->second));
  }

  sort(v.begin(), v.end(), comp1);

  for (int i = 0; i < v.size(); i++) {
    string genre = v[i].first;
    vector<pair<int, int>> vec;
    
    multimap<string, pair<int, int>>::iterator st = m.equal_range(genre).first;
    multimap<string, pair<int, int>>::iterator end =
        m.equal_range(genre).second;

    for (multimap<string, pair<int, int>>::iterator it = st; it != end; ++it) {
      vec.emplace_back(make_pair(it->second.first, it->second.second));
    }

    sort(vec.begin(), vec.end(), comp2);

    if (vec.size() >= 2) {
      for (int i = 0; i < 2; i++) {
        answer.push_back(vec[i].second);
      }
    } else {
      answer.push_back(vec[0].second);
    }
  }

  return 0;
}