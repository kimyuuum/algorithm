//
//  10026.cpp
//  
//
//  Created by 김유민 on 2020/02/11.
//

#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100;
int rgb=0;
int rb=0;
int n;

queue<pair<int,int> > q;
queue<pair<int,int> > q2;

char map[MAX][MAX];
bool visited[MAX][MAX] = {false,};
bool visited2[MAX][MAX] = {false,};

int dirX[4] = {0,1,0,-1};
int dirY[4] = {-1,0,1,0};

void bfs(int x, int y){
    
    q.push(make_pair(x,y));
    
    visited[x][y] = true;
    
    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        char color = map[curX][curY];
        q.pop();
        
        for(int i=0; i<4; i++){
            int nextX = curX + dirX[i];
            int nextY = curY + dirY[i];
            
            if(nextX < 0 || nextX >= n || nextY < 0 || nextY >= n)
                continue;
            if(color != map[nextX][nextY] || visited[nextX][nextY])
                continue;
            q.push(make_pair(nextX,nextY));
            visited[nextX][nextY] = true;
        }
    }
    rgb++;
}

void bfs2(int x, int y){
    
    q2.push(make_pair(x,y));
    
    visited2[x][y] = true;
    
    while(!q2.empty()){
        int curX = q2.front().first;
        int curY = q2.front().second;
        char color = map[curX][curY];
        q2.pop();
        
        for(int i=0; i<4; i++){
            int nextX = curX + dirX[i];
            int nextY = curY + dirY[i];
            
            if(nextX < 0 || nextX >= n || nextY < 0 || nextY >= n)
                continue;
            if(visited2[nextX][nextY])
                continue;
            if(color == 'R' || color == 'G')
                if(map[nextX][nextY] == 'B')
                    continue;
            if(color == 'B')
                if(map[nextX][nextY] != 'B')
                    continue;
            
            q2.push(make_pair(nextX,nextY));
            visited2[nextX][nextY] = true;
        }
    }
    rb++;
}

int main(){

    cin>>n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>map[j][i];
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visited[j][i]){
                bfs(j,i);
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visited2[j][i]){
                bfs2(j,i);
            }
        }
    }
    
    cout<<rgb<<" "<<rb;
    
    return 0;
}
