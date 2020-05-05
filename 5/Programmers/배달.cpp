#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 51;
const int INF = 987654321;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    pq;
vector<pair<int, int>> v[MAX];
int dist[MAX];

int solution(int N, vector<vector<int>> road, int K) {
  int answer = 0;
  dist[1] = 0;
  for (int i = 2; i < 51; i++) {
    dist[i] = INF;
  }

  for (int i = 0; i < road.size(); i++) {
    int a = road[i][0];
    int b = road[i][1];
    int val = road[i][2];

    v[a].push_back(make_pair(b, val));
    v[b].push_back(make_pair(a, val));
  }

  pq.push(make_pair(0, 1));

  while (!pq.empty()) {
    int cost = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    if (dist[node] < cost) {
      continue;
    }

    for (int i = 0; i < v[node].size(); i++) {
      int nextnode = v[node][i].first;
      int nextcost = cost + v[node][i].second;

      if (nextcost < dist[nextnode]) {
        dist[nextnode] = nextcost;
        pq.push(make_pair(nextcost, nextnode));
      }
    }
  }

  for (int i = 1; i <= N; i++) {
    if (dist[i] <= K) {
      answer++;
    }
  }

  return answer;
}