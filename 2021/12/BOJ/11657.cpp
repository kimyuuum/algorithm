#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;
long long dist[505];
vector<pair<pair<int, int>, int> > v;
int N, M;
bool isCyclic = false;

void belman_ford() {
  dist[1] = 0;

  for (int idx = 0; idx < N - 1; idx++) {
    for (int i = 0; i < M; i++) {
      int from = v[i].first.first;
      int to = v[i].first.second;
      int cost = v[i].second;

      if (dist[from] == INF) {
        continue;
      }

      if (dist[to] > dist[from] + cost) {
        dist[to] = dist[from] + cost;
      }
    }
  }

  for (int i = 0; i < M; i++) {
    int from = v[i].first.first;
    int to = v[i].first.second;
    int cost = v[i].second;

    if (dist[from] == INF) {
      continue;
    }
    if (dist[to] > dist[from] + cost) {
      isCyclic = true;
      break;
    }
  }

  return;
}

int main() {
  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    v.push_back(make_pair(make_pair(a, b), c));
  }

  for (int i = 1; i <= N; i++) {
    dist[i] = INF;
  }

  belman_ford();

  if (isCyclic) {
    cout << -1;
  } else {
    for (int i = 2; i <= N; i++) {
      if (dist[i] == INF) {
        cout << -1 << endl;
      } else {
        cout << dist[i] << endl;
      }
    }
  }
  return 0;
}