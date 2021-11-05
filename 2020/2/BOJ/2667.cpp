//
//  2667.cpp
//  
//
//  Created by 김유민 on 2020/02/09.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 25;
int arr[MAX][MAX];
bool visited[MAX][MAX] = {false,};
int result = 0;
int n;
int dirX[4] = {0,1,0,-1};
int dirY[4] = {-1,0,1,0};
queue<pair<int,int> > q;
vector<int> res;

void bfs(int x,int y){
    
    int num = 0;
    
    q.push(make_pair(x,y));
    visited[x][y] = true;
    
    while(!q.empty()){
        
        int curX = q.front().first;
        int curY = q.front().second;
        
        q.pop();
        
        for(int i=0; i<4; i++){
            int nextX = curX + dirX[i];
            int nextY = curY + dirY[i];
            
            if( 0 > nextX || n <= nextX || 0 > nextY || n <= nextY)
                continue;
            if(visited[nextX][nextY] || arr[nextX][nextY] == 0)
                continue;
            q.push(make_pair(nextX,nextY));
            visited[nextX][nextY] = true;
        }
        num++;
    }
    
    res.push_back(num);
}

int main(){
    
    cin>>n;
    
    char input;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>input;
            arr[j][i] = input - 48;
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[j][i] == 1 && !visited[j][i]){
                bfs(j,i);
                result++;
            }
        }
    }
    
    sort(res.begin(),res.end());
    
    cout<<result<<"\n";
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<"\n";
    }
    
    return 0;
}
