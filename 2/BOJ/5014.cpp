//
//  5014.cpp
//  
//
//  Created by 김유민 on 2020/02/25.
//

#include <iostream>
#include <queue>
using namespace std;
const int MAX = 1000000;
int f,s,g,u,d;
bool visited[MAX];
int val[MAX] = {0,};
//s = 현재위치
//g = 목표위치

int bfs(){
    queue<int> q;
    
    q.push(s);
    val[s] = 0;
    visited[s] = true;
    
    int count=0;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        if(cur == g)
            return val[g];
        
        int up = cur + u;
        int down = cur - d;
        if(up <= f && !visited[up]){
            q.push(up);
            visited[up] = true;
            val[up] = val[cur] + 1;
        }
        if(down >= 1 && !visited[down]){
            q.push(down);
            visited[down] = true;
            val[down] = val[cur] + 1;
        }

    }
    
    return -1;
}

int main(){
    
    cin>>f>>s>>g>>u>>d;
    
    int result = bfs();
    if(result == -1)
        cout<<"use the stairs";
    else
        cout<<result;
    
    return 0;
}
