//
//  13549.cpp
//  
//
//  Created by 김유민 on 2020/03/06.
//

#include <iostream>
#include <queue>
using namespace std;
const int MAX = 1000001;
int n,k;
bool visited[MAX];
int res = -1;

int bfs(){
    
    queue<pair<int,int> > q;
    q.push(make_pair(n,0));
    visited[n] = true;
    
    while(!q.empty()){
        int curX = q.front().first;
        int curT = q.front().second;
        q.pop();
        visited[curX] = true;

        if(curX == k && res == -1)
            res = curT;
        if(curX == k && res != -1){
            if(curT < res){
                res = curT;
            }
        }
        
        if(curX+1 < MAX && !visited[curX+1]){
            q.push(make_pair(curX+1,curT+1));
        }
        if(curX-1 >= 0 && !visited[curX-1]){
            q.push(make_pair(curX-1,curT+1));
        }
        if(curX*2 < MAX && !visited[curX*2]){
            q.push(make_pair(curX*2,curT));
        }
        
    }
    
    return res;
}

int main(){
        
    cin>>n>>k;
    int result = bfs();
    cout<<result;
    
    return 0;
}
