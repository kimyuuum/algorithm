//
//  15649_1.cpp
//  
//
//  Created by 김유민 on 2020/01/21.
//

#include <iostream>
#include <vector>
using namespace std;

int n,m;
vector<int> v;
bool visited[8];

void dfs(int count){
    
    if(count == m){
        for(int i=0; i<v.size(); i++){
            cout<<v[i]<<" ";
        }
        cout<<"\n";
    }
    
    else{
        for(int i=0; i<n; i++){
            if(visited[i] == true)
                continue;
            else{
                visited[i] = true;
                v.push_back(i+1);
                dfs(count+1);
                v.pop_back();
                visited[i] = false;
            }
        }
    }
    
}

int main(){
    
    cin>>n>>m;
    
    dfs(0);
    
    return 0;
}
