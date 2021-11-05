#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int MAX = 10005;
bool visited[MAX];
vector<string> answer;
vector<string> temp;

bool dfs(string from, vector<vector<string>> tickets, int cnt) {
  
  temp.push_back(from);

  if (cnt == tickets.size()) {
    answer = temp;
    return true;
  }

  for (int i = 0; i < tickets.size(); i++) {
    if (tickets[i][0] == from && !visited[i]) {
      visited[i] = true;
      bool success = dfs(tickets[i][1], tickets, cnt + 1);
      if (success) {
        return true;
      }
      visited[i] = false;
    }
  }

  temp.pop_back();
  return false;
}

vector<string> solution(vector<vector<string>> tickets) {
  memset(visited, false, sizeof(visited));

  sort(tickets.begin(), tickets.end());

  string from = "ICN";
  dfs(from, tickets, 0);

  return answer;
}

int main() {
  // vector<vector<string>> tickets = {{"ICN", "JFK"}, {"HND", "IAD"}, {"JFK",
  // "HND"}};
  vector<vector<string>> tickets = {
      {"ICN", "ABC"}, {"ICN", "KVE"}, {"KVE", "ICN"}};
  // vector<vector<string>> tickets = {{"ICN", "SFO"},
  //                                   {"ICN", "ATL"},
  //                                   {"SFO", "ATL"},
  //                                   {"ATL", "ICN"},
  //                                   {"ATL", "SFO"}};
  vector<string> ans = solution(tickets);
  for (int i = 0; i < answer.size(); i++) {
    cout << answer[i] << " ";
  }
  return 0;
}