//
//  12851.cpp
//  
//
//  Created by 김유민 on 2020/03/04.
//

#include <iostream>
#include <queue>
using namespace std;
const int MAX = 1000001;
bool visited[MAX];
int n,k;

void bfs(){

    queue<pair<int,int> > q;
    
    q.push(make_pair(n,0));
    visited[n] = true;
    
    int cnt = 0;
    int res = 0;
    
    while(!q.empty()){
        
        int curX = q.front().first;
        int curT = q.front().second;
        q.pop();
        
        visited[curX] = true;
        
        if(res != 0 && res == curT && curX == k){
            cnt++;
        }
        
        if(res == 0 && curX == k){
            res = curT;
            cnt++;
        }
        if(curX-1 >= 0 && !visited[curX-1])
            q.push(make_pair(curX-1,curT+1));
        if(curX+1 <= 1000000 && !visited[curX+1])
            q.push(make_pair(curX+1,curT+1));
        if(curX*2 <= 1000000 && !visited[curX*2])
            q.push(make_pair(curX*2,curT+1));
    }
    
    cout<<res<<"\n"<<cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    bfs();
    
    return 0;
}
