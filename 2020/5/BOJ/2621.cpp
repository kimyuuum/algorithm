#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
vector<pair<char, int>> v;
multimap<char, int> m;
int number[10];
int color[4];  // 0 = R 1 = B 2 = Y 3 = G
bool comp(pair<char, int> p1, pair<char, int> p2) {
  if (p1.first < p2.first) {
    return true;
  } else if (p1.first == p2.first) {
    if (p1.second < p2.second) {
      return true;
    }
  }

  return false;
}

int main() {
  for (int i = 0; i < 5; i++) {
    char c;
    int a;
    cin >> c >> a;
    if (c == 'R') {
      color[0]++;
    } else if (c == 'B') {
      color[1]++;
    } else if (c == 'Y') {
      color[2]++;
    } else {
      color[3]++;
    }

    number[a]++;

    v.push_back(make_pair(c, a));
  }

  sort(v.begin(), v.end(), comp);
  for (int i = 0; i < v.size(); i++) {
    m.insert({v[i].first, v[i].second});
  }

  multimap<char, int>::iterator iter;
  int res = 0;
  int score = 0;
  // case1
  if (m.count(m.begin()->first) == 5) {
    for (int i = 1; i < 10; i++) {
      if (number[i] != 0 && i <= 5) {
        int cnt = 1;
        for (int j = i + 1; j < i + 5; j++) {
          if (number[j] != 0) {
            cnt++;
          }
        }
        if (cnt == 5) {
          res = i + 4 + 900;
        }
      }
    }
  }
  // case2
  int num = 0;
  for (int i = 1; i < 10; i++) {
    if (number[i] == 4) {
      num = i;
    }
  }
  if (num != 0) {
    score = 800 + num;
    if (res < score) {
      res = score;
    }
  }
  // case3
  int num1 = 0, num2 = 0;
  for (int i = 1; i < 10; i++) {
    if (number[i] == 3) {
      num1 = i;
    } else if (number[i] == 2) {
      num2 = i;
    }
  }
  if (num1 != 0 && num2 != 0) {
    score = 700 + num1 * 10 + num2;
    if (res < score) {
      res = score;
    }
  }
  // case4
  if (m.count(m.begin()->first) == 5) {
    int idx = 0;
    for (int i = 9; i >= 1; i--) {
      if (number[i] != 0) {
        idx = i;
        break;
      }
    }
    score = 600 + idx;
    if (res < score) {
      res = score;
    }
  }
  // case5
  for (int i = 1; i < 10; i++) {
    if (number[i] != 0 && i <= 5) {
      int cnt = 1;
      for (int j = i + 1; j < i + 5; j++) {
        if (number[j] != 0) {
          cnt++;
        } else {
          break;
        }
      }
      if (cnt == 5) {
        score = i + 4 + 500;
        if (res < score) {
          res = score;
        }
      }
    }
  }
  // case6
  num = 0;
  for (int i = 1; i < 10; i++) {
    if (number[i] == 3) {
      num = i;
    }
  }
  if (num != 0) {
    score = num + 400;
    if (score > res) {
      res = score;
    }
  }
  // case7
  num1 = 0;
  num2 = 0;
  for (int i = 1; i < 10; i++) {
    if (num1 == 0 && number[i] == 2) {
      num1 = i;
    } else if (num1 != 0 && number[i] == 2) {
      num2 = i;
    }
  }
  if (num1 != 0 && num2 != 0) {
    score = num2 * 10 + num1 + 300;
    if (score > res) {
      res = score;
    }
  }

  // case8
  num = 0;
  for (int i = 1; i < 10; i++) {
    if (number[i] == 2) {
      num = i;
    }
  }
  if (num != 0) {
    score = num + 200;
    if (res < score) {
      res = score;
    }
  }

  // case9
  num = 0;
  for (int i = 9; i >= 1; i--) {
    if (number[i] != 0) {
      num = i;
      break;
    }
  }
  score = num + 100;
  if (res < score) {
    res = score;
  }

  cout << res;
  return 0;
}