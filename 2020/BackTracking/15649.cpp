//
//  15649.cpp
//  
//
//  Created by 김유민 on 2019/12/23.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int arr[8];
bool visited[8];

void dfs(int cnt,int n, int m){
    
    if(cnt == m){
        for(int i=0; i<v.size(); i++){
            cout<<v[i]<<" ";
        }
        cout<<"\n";
    }
    else{
        for(int idx = 0; idx < n; idx++){
            if(visited[idx] == true)
                continue;
            else{
                visited[idx] = true;
                v.push_back(arr[idx]);
                dfs(cnt+1,n,m);
                v.pop_back();
                visited[idx] = false;
            }
        }
    }
}

int main(){
    
    int n,m;
    cin>>n>>m;
    
    for(int i=1; i<=n; i++){
        arr[i-1] = i;
    }
    
    dfs(0,n,m);
    
    return 0;
}
