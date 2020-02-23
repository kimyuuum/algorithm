//
//  2468.cpp
//  
//
//  Created by 김유민 on 2020/02/20.
//

// 잠기지 않는 안전한 영역이 최대가 몇개인지.
// 비의 양에 따라 일정한 높이 이하의 모든 지점은 잠긴다.
// 높이가 4 이하인 지점이 잠기면 4이하로 다 잠김
// 크기 최대 영역 구해야 함.
// 장마철에 물에 잠기지 않는 안전한 영역의 최대 개수

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 100;
queue<pair<int,int> > q;

int dirX[4] = {0,1,0,-1};
int dirY[4] = {-1,0,1,0};

int n;
int result = 0;
int arr[MAX][MAX];
bool visited[MAX][MAX] = {false,};
int sinked[MAX][MAX] = {0,};
int depth = 0;

void bfs(int x,int y){
    
    q.push(make_pair(x,y));
    visited[x][y] = true;
    
    while(!q.empty()){
        
        int curX = q.front().first;
        int curY = q.front().second;
        
        q.pop();
        for(int i=0; i<4; i++){
            
            int nextX = curX + dirX[i];
            int nextY = curY + dirY[i];
            
            if(nextX < 0 || nextX >= n || nextY < 0 || nextY >= n)
                continue;
            if(visited[nextX][nextY] || sinked[nextX][nextY] == 0)
                continue;
            visited[nextX][nextY] = true;
            q.push(make_pair(nextX,nextY));
        }
    }
    
}

int main(){
    int res2;
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[j][i];
            if(arr[j][i] > depth)
                depth = arr[j][i];
        }
    }
    
    while(depth--){
        
        int width = 0;
        
        memset(sinked,0,sizeof(sinked));
        memset(visited,0,sizeof(visited));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(arr[j][i] > depth){
                    sinked[j][i] = 1;
                }
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(sinked[j][i] == 1 && !visited[j][i]){
                    bfs(j,i);
                    width++;
                }
            }
        }
        
        if(width > result){
            result = width;
        }
        
    }
    
    cout<<result;
    
    return 0;
}
