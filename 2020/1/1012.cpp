//
//  1012.cpp
//  
//
//  Created by 김유민 on 2020/01/07.
//

#include <iostream>
using namespace std;

int m,n,k;
int field[51][51] = {0,};
bool visited[51][51];

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int count=0;

void dfs(int y, int x){
    
    visited[y][x] = true;
    
    for(int j=0; j<4; j++){
        int nextX = x + dx[j];
        int nextY = y + dy[j];
        if(0 <= nextX && nextX < m && 0 <= nextY && nextY < n){
            if(field[nextY][nextX] && !visited[nextY][nextX]){
                dfs(nextY,nextX);
            }
        }
    }
}

int main(){
    
    int testcase;
    int x,y;
    
    cin>>testcase;
    
    for(int i=0; i<testcase; i++){
        
        memset(field,0,sizeof(field));
        memset(visited,false,sizeof(visited));
        
        cin>>m>>n>>k;
        
        for(int j=0; j<k; j++){
            cin>>x>>y;
            field[y][x] = 1;
        }

        int cnt = 0;
        
        for(int a=0; a<n; a++){
            for(int b=0; b<m; b++){
                if(field[a][b] && !visited[a][b]){
                    dfs(a,b);
                    cnt++;
                }
            }
        }
        cout<<cnt<<"\n";
    }

    
    return 0;
}
