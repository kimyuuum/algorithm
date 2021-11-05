//
//  dfs.cpp
//  
//
//  Created by 김유민 on 2019/12/27.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n,m,start;
vector<int> v[1001];
bool visited[1001];

void dfs(int start){
    
    visited[start] = true;
    cout<<start<<" ";
    
    for(int i : v[start]){
        if(!visited[i]){
            dfs(i);
        }
    }
    
}

void bfs(int start){
    queue<int> q;
    
    visited[start] = true;
    q.push(start);
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<" ";
        for(int i=0; i<v[node].size(); i++){
            if(!visited[v[node][i]]){
                visited[v[node][i]] = true;
                q.push(v[node][i]);
            }
        }
    }
    
    
}

int main(){
    int node1,node2;

    cin>>n>>m>>start;
    
    for(int i=0; i<m; i++){
        cin>>node1>>node2;
        v[node1].push_back(node2);
        v[node2].push_back(node1);
    }
    
    for(int i=1; i<=n; i++){
        sort(v[i].begin(),v[i].end());
    }
    
    dfs(start);
    cout<<"\n";
    memset(visited,false,sizeof(visited));
    bfs(start);
    
    return 0;
}
