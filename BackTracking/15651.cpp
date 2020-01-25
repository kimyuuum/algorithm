//
//  15651.cpp
//  
//
//  Created by 김유민 on 2020/01/21.
//

#include <iostream>
#include <vector>
using namespace std;

int n,m;
vector<int> v;

void solve(int count){

    if(count == m){
        for(int i=0; i<v.size(); i++){
            cout<<v[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    
    for(int i=0; i<n; i++){
        v.push_back(i+1);
        solve(count+1);
        v.pop_back();
    }
}

int main(){
    
    cin>>n>>m;
    
    solve(0);
    
}
