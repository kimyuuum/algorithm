//
//  1012_1.cpp
//  
//
//  Created by 김유민 on 2020/01/27.
//

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int MAX = 51;

int T,m,n,k;
int cabbage[MAX][MAX] = {0,};
bool visited[MAX][MAX] = {false,};
queue<pair<int,int> > q;
int dirX[4] = {0,1,0,-1};
int dirY[4] = {-1,0,1,0};

void bfs(int x, int y){
    
    q.push(make_pair(x,y));
    visited[x][y] = true;
    
    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        
        q.pop();
        for(int i=0; i<4; i++){
            int nextX = curX + dirX[i];
            int nextY = curY + dirY[i];
            
            if(nextX < 0 || nextX >= m || nextY < 0 || nextY >= n)
                continue;
            if(!cabbage[nextX][nextY])
                continue;
            if(visited[nextX][nextY])
                continue;
            
            q.push(make_pair(nextX,nextY));
            visited[nextX][nextY] = true;
        
        }
        
    }
    
    
}
int main(){
    
    cin>>T;
    int x,y;
    
    for(int t=0; t<T; t++){
        
        memset(cabbage,0,sizeof(cabbage));
        memset(visited,0,sizeof(visited));
        
        int warm = 0;
        
        cin>>m>>n>>k;
        
        for(int i=0; i<k; i++){
            cin>>x>>y;
            cabbage[x][y] = 1;
        }
        
        for(int a=0; a<m; a++){
            for(int b=0; b<n; b++){
                if(cabbage[a][b] == 1 && !visited[a][b]){
                    bfs(a,b);
                    warm++;
                }
            }
        }
        cout<<warm<<"\n";
    }
    
    return 0;
}


