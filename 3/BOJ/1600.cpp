//
//  1600.cpp
//  
//
//  Created by 김유민 on 2020/03/14.
//

#include <iostream>
#include <queue>
using namespace std;
const int MAX = 201;
int k,w,h;
int map[MAX][MAX];
bool visited[MAX][MAX][32];
int hDirX[8] = {-1,1,2,2,1,-1,-2,-2};
int hDirY[8] = {-2,-2,-1,1,2,2,1,-1};
int dirX[4] = {0,1,0,-1};
int dirY[4] = {-1,0,1,0};

int bfs(){
    queue<pair<pair<int,int>,int> >q;
    q.push(make_pair((make_pair(0,0)),0));
    visited[0][0][0] = true;
    int cnt = 0;
    
    while(!q.empty()){
        int size = q.size();
        for(int i=0; i<size; i++){
            int curX = q.front().first.first;
            int curY = q.front().first.second;
            int curK = q.front().second;
            q.pop();
            if(curX == w-1 && curY == h-1)
                return cnt;
            if(curK < k){
                for(int i=0; i<8; i++){
                    int nextX = curX + hDirX[i];
                    int nextY = curY + hDirY[i];
                    int nextK = curK + 1;
                    if(nextX < 0 || nextX > w || nextY < 0 || nextY > h)
                        continue;
                    if(map[nextX][nextY] || visited[nextX][nextY][nextK])
                        continue;
                    
                    q.push(make_pair((make_pair(nextX,nextY)),nextK));
                    visited[nextX][nextY][nextK] = true;
                }
            }
            
            for(int i=0; i<4; i++){
                int nextX = curX + dirX[i];
                int nextY = curY + dirY[i];

                if(nextX < 0 || nextX > w || nextY < 0 || nextY > h)
                    continue;
                if(map[nextX][nextY] || visited[nextX][nextY][curK])
                    continue;
                q.push(make_pair((make_pair(nextX,nextY)),curK));
                visited[nextX][nextY][curK] = true;
            }
        }
        cnt++;
    }
    
    return -1;
}
int main(){
    
    cin>>k>>w>>h;
    
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin>>map[j][i];
        }
    }
    
    int result = bfs();
    cout<<result;
    
    return 0;
}
