//
//  1926.cpp
//  
//
//  Created by 김유민 on 2020/02/04.
//

#include <iostream>
#include <queue>
using namespace std;

int n,m;
int arr[502][502] = {0,};
bool visited[502][502] = {false,};

int dirX[4] = {0,1,0,-1};
int dirY[4] = {-1,0,1,0};
queue<pair<int,int> > q;
int result = 0;

int bfs(int x,int y){
    
    int width = 1;
    
    visited[x][y] = true;
    q.push(make_pair(x,y));
    
    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nextX = curX + dirX[i];
            int nextY = curY + dirY[i];
    
            if((nextX >= 0 && nextX < m) && (nextY >= 0 && nextY < n)){
                if(arr[nextX][nextY] == 1 && !visited[nextX][nextY]){
                    q.push(make_pair(nextX,nextY));
                    visited[nextX][nextY] = true;
                    width++;
                }
            }
        }
    }
//
//    if(width > result)
//        result = width;
    return width;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>m;
    int count = 0;
    int max = 0;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[j][i];
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[j][i] == 1 && !visited[j][i]){
                int result = bfs(j,i);
                if(max < result)
                    max = result;
                count++;
            }
        }
    }
    
    cout<<count<<"\n"<<max<<"\n";
    
    return 0;
}
