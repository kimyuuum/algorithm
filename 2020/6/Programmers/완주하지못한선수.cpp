#include <set>
#include <string>
#include <vector>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
  string answer = "";
  multiset<string> m;
  for (int i = 0; i < participant.size(); i++) {
    string name = participant[i];
    m.insert(name);
  }

  for (int i = 0; i < completion.size(); i++) {
    string target = completion[i];
    set<string>::iterator iter;
    iter = m.find(target);
    m.erase(iter);
  }

  answer = *m.begin();
  return 0;
}