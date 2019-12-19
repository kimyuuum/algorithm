//
//  1158.cpp
//  
//
//  Created by 김유민 on 2019/12/18.
//

#include <list>
#include <iostream>
#include <vector>
using namespace std;

list<int> josephus;
vector<int> result;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,target;
    
    cin>>n>>target;
    
    for(int i=1; i<=n; ++i){
        josephus.push_back(i);
    }

    list<int>::iterator idx = josephus.begin();
    int N = n;

    while(N > 0){
        for(int i=1; i<target; i++){
            if(idx == josephus.end())
                idx = josephus.begin();
            idx++;
            if(idx == josephus.end())
                idx = josephus.begin();
        }
        result.push_back(*idx);
        idx = josephus.erase(idx);
        
        N--;
    }
    
    cout<<"<";
    for(int i=0; i<result.size()-1; i++){
        cout<<result[i]<<", ";
    }
    cout<<result[result.size()-1];
    cout<<">";
    
    
    return 0;
}
