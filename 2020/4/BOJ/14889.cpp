
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 21;
int s[MAX][MAX];
bool isUsed[MAX];
int stat = 987654321;
int n;

void dfs(int idx, int depth) {
  if (depth == (n / 2)) {
    vector<int> start;
    vector<int> link;

    for (int i = 1; i <= n; i++) {
      if (isUsed[i]) {
        start.push_back(i);
      } else {
        link.push_back(i);
      }
    }

    int tstart = 0;
    for (int i = 0; i < start.size(); i++) {
      for (int j = i + 1; j < start.size(); j++) {
        int val = s[start[i]][start[j]] + s[start[j]][start[i]];
        tstart += val;
      }
    }

    int tlink = 0;
    for (int i = 0; i < link.size(); i++) {
      for (int j = i + 1; j < link.size(); j++) {
        int val = s[link[i]][link[j]] + s[link[j]][link[i]];
        tlink += val;
      }
    }

    stat = min(stat, abs(tstart - tlink));

    return;
  }

  for (int i = idx; i <= n; i++) {
    if (!isUsed[i]) {
      isUsed[i] = true;
      dfs(i, depth + 1);
      isUsed[i] = false;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> s[j][i];
    }
  }

  dfs(1, 0);

  cout << stat;
  return 0;
}