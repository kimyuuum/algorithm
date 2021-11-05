//
//  2178_1.cpp
//  
//
//  Created by 김유민 on 2020/01/27.
//

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 100;
int n,m;
string input;
int dist[MAX][MAX] = {0,};
int arr[MAX][MAX];
queue<pair<int,int> > maze;

int dirX[4] = {0,1,0,-1};
int dirY[4] = {-1,0,1,0};

void bfs(int x, int y){
    
    maze.push(make_pair(x,y));
    dist[x][y] = 1;
    
    while(!maze.empty()){
        int curX = maze.front().first;
        int curY = maze.front().second;
        maze.pop();
        for(int i=0; i<4; i++){
            int nextX = curX + dirX[i];
            int nextY = curY + dirY[i];
            
            if(nextX < 0 || nextX >= n || nextY < 0 || nextY >= m)
                continue;
            if(!arr[nextX][nextY])
                continue;
            if(dist[nextX][nextY])
                continue;
            maze.push(make_pair(nextX,nextY));
            dist[nextX][nextY] = dist[curX][curY] + 1;
        }
    }
    
}

int main(){
    
    cin>>n>>m;
    
    for(int i=0; i<n; i++){
        cin>>input;
        for(int j=0; j<input.size(); j++){
            arr[i][j] = input[j] - 48;
        }
    }

    bfs(0,0);
    
    cout<<dist[n-1][m-1];
    
    return 0;
}
