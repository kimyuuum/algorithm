//
//  1697_1.cpp
//  
//
//  Created by 김유민 on 2020/01/27.
//

#include <iostream>
#include <queue>
using namespace std;
const int MAX = 100001;

int n,k,res = 0;
queue<pair<int,int> > q;
bool visited[MAX] = {false,};

void bfs(){
    
    q.push(make_pair(n,0));
    visited[n] = true;
    
    while(!q.empty()){
        int cur = q.front().first;
        int cursec = q.front().second;
        if(cur == k){
            res = cursec;
            break;
        }
        q.pop();
        if(cur+1<=100000 && !visited[cur+1]){
            q.push(make_pair(cur+1,cursec+1));
            visited[cur+1] = true;
        }
        if(cur-1>=0 && !visited[cur-1]){
            q.push(make_pair(cur-1,cursec+1));
            visited[cur-1] = true;
        }
        if(cur*2 <= 100000 && !visited[cur*2]){
            q.push(make_pair(cur*2,cursec+1));
            visited[cur*2] = true;
        }
    }
    
}

int main(){
    
    cin>>n>>k;
    bfs();
    cout<<res<<"\n";
    
    return 0;
    
}
