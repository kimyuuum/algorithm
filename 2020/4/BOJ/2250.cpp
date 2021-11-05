
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 10001;
vector<int> v[MAX];
vector<int> level[MAX];
bool visited[MAX];
int findnode[MAX];
int n, idx = 1;
int lev = 0;

void midTraverse(int cur, int depth) {
  if (v[cur][0] != -1) {
    int nextNode = v[cur][0];
    midTraverse(nextNode, depth + 1);
  }

  if (!visited[cur]) {
    level[depth].push_back(idx);
    idx++;
    visited[cur] = true;
    if (lev < depth) {
      lev = depth;
    }
  }

  if (v[cur][1] != -1) {
    int nextNode = v[cur][1];
    midTraverse(nextNode, depth + 1);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  while (n--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a != -1) {
      findnode[a]++;
    }
    if (b != -1) {
      findnode[b]++;
    }
    if (c != -1) {
      findnode[c]++;
    }
    v[a].push_back(b);
    v[a].push_back(c);
  }

  int root;

  for (int i = 1; i < MAX; i++) {
    if (findnode[i] == 1) {
      root = i;
    }
  }

  midTraverse(root, 1);
  pair<int, int> res;

  for (int i = 1; i <= lev; i++) {
    int size;
    if (level[i].size() == 1) {
      size = 1;
    } else {
      size = level[i][level[i].size() - 1] - level[i][0] + 1;
    }
    if (res.second < size) {
      res.first = i;
      res.second = size;
    }
  }

  cout << res.first << " " << res.second;
  return 0;
}