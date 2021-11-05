//
//  2206.cpp
//  
//
//  Created by 김유민 on 2020/02/11.
//

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int MAX = 1000;

queue<pair<pair<int,int>, int> > q;

int n,m;
int map[MAX][MAX];
int record[MAX][MAX][2];
bool visited[MAX][MAX] = {false,};
int destroy = 1;
int result = 0;
int dirX[4] = {0,1,0,-1};
int dirY[4] = {-1,0,1,0};

int bfs(int x, int y){
    q.push(make_pair(make_pair(x,y),1));
    record[x][y][1] = 1;
    
    while(!q.empty()){
        
        int curX = q.front().first.first;
        int curY = q.front().first.second;
        int block = q.front().second;
        q.pop();
        
        if(curX == m-1 && curY == n-1)
            return record[m-1][n-1][block];
        
        for(int i=0; i<4; i++){
            int nextX = curX + dirX[i];
            int nextY = curY + dirY[i];
            
            if(nextX < 0 || nextX >= m || nextY < 0 || nextY >= n)
                continue;
            if(map[nextX][nextY] == 1 && block){
                record[nextX][nextY][block-1] = record[curX][curY][block] + 1;
                q.push(make_pair(make_pair(nextX,nextY),block-1));
            }
            else if(map[nextX][nextY] == 0 && record[nextX][nextY][block] == 0){
                record[nextX][nextY][block] = record[curX][curY][block] + 1;
                q.push(make_pair(make_pair(nextX,nextY),block));
            }
        }
    }
    return -1;
}

int main(){
    cin>>n>>m;
    char input;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>input;
            map[j][i] = input - 48;
        }
    }
    
    
    cout<<bfs(0,0);
    return 0;
}
