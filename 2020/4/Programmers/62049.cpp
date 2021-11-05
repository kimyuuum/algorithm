#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<int> v;
    answer.push_back(0);
    
    for(int i=1; i<n; i++){
        v.clear();
        int mid = answer.size()/2;
        v = answer;
        answer.push_back(0);
        v[mid] = 1;
        for(int j=0; j<v.size(); j++){
            answer.push_back(v[j]);
        }
    }
    
    return answer;
}

