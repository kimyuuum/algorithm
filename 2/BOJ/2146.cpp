//
//  2146.cpp
//  
//
//  Created by 김유민 on 2020/02/24.
//

#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 100;

int map[MAX][MAX] = {0,};
bool visited[MAX][MAX] = {false,};
int n;
int dirX[4] = {0,1,0,-1};
int dirY[4] = {-1,0,1,0};

void island(int x,int y,int count){
    
    queue<pair<int,int> > q;
    q.push(make_pair(x,y));
    visited[x][y] = true;
    map[x][y] = count;
    
    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nextX = curX + dirX[i];
            int nextY = curY + dirY[i];
            
            if(nextX >=0 && nextX < n && nextY >= 0 && nextY < n){
                if(map[nextX][nextY] == 1 && !visited[nextX][nextY]){
                    q.push(make_pair(nextX,nextY));
                    visited[nextX][nextY] = true;
                    map[nextX][nextY] = count;
                }
            }
        }
    }
    
}

int bfs(int num){
    int idx = 0;
    queue<pair<int,int> >q;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(map[j][i] == num){
                q.push(make_pair(j,i));
                visited[j][i] = true;
            }
        }
    }
    
    while(!q.empty()){
        int size = q.size();
        for(int s=0; s<size; s++){
            int curX = q.front().first;
            int curY = q.front().second;
            q.pop();
            
            for(int i=0; i<4; i++){
                int nextX = curX + dirX[i];
                int nextY = curY + dirY[i];
                
                if(nextX >= 0 && nextX < n && nextY >= 0 && nextY < n){
                    if(map[nextX][nextY] != 0 && map[nextX][nextY] != num)
                        return idx;
                    else if(map[nextX][nextY] == 0 && !visited[nextX][nextY]){
                        q.push(make_pair(nextX,nextY));
                        visited[nextX][nextY] = true;
                    }
                }
            }
        }
        idx++;
    }
}

int main(){
    
    cin>>n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>map[j][i];
        }
    }
    
    int count = 1;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(map[j][i] == 1 && !visited[j][i]){
                island(j,i,count++);
            }
        }
    }
    
    int res = 210;
    
    for(int i=1; i<count; i++){
        memset(visited,false,sizeof(visited));
        res = min(res,bfs(i));
    }
    
    cout<<res;
    
    return 0;
}
