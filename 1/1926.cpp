//
//  1926.cpp
//  
//
//  Created by 김유민 on 2020/01/26.
//

#include <iostream>
#include <queue>
using namespace std;

queue<pair<int,int> > q;
int n,m,num;
bool visited[502][502] = {false,};
int pic[502][502];

int dirX[4] = {0,1,0,-1};
int dirY[4] = {-1,0,1,0};

int picCount = 0, result = 0;
int width = 0;

void bfs(int x, int y){
    int width = 1;
    q.push(make_pair(x,y));
    visited[x][y] = true;
    
    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        
        q.pop();
        
        for(int i=0; i<4; i++){
            int nextX = curX + dirX[i];
            int nextY = curY + dirY[i];
            
            if(visited[nextX][nextY])
                continue;
            if(!pic[nextX][nextY])
                continue;
            if(0 > nextX || m < nextX || 0 > nextY || n < nextY)
                continue;
            q.push(make_pair(nextX,nextY));
            visited[nextX][nextY] = true;
            width++;
        }
    }
    
    if(width > result){
        result = width;
    }
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>m;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>pic[j][i];
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(pic[j][i] == 1 && !visited[j][i]){
                bfs(j,i);
                picCount++;
            }
        }
    }
    
    cout<<picCount<<"\n"<<result<<"\n";
    
    return 0;
}
