//
//  1926.cpp
//  
//
//  Created by 김유민 on 2019/12/27.
//

#include <iostream>
using namespace std;

typedef struct{
    int y,x;
} Dir;

Dir moveDir[4] = {{1,0},{-1,0},{0,1},{0,-1}};
int n,m;
int width = 0;
int result;

int arr[502][502];
bool visited[502][502];

void dfs(int y, int x){
    
    width++;
    visited[y][x] = true;
    
    for(int i=0; i<4; i++){
        int nextY = y + moveDir[i].y;
        int nextX = x + moveDir[i].x;
        
        if((0 <= nextY && nextY < n) && (0<=nextX && nextX < m)){
            if(!visited[nextY][nextX] && arr[nextY][nextX])
                dfs(nextY,nextX);
        }
    }
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int count = 0;
    cin>>n>>m;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!visited[i][j] && arr[i][j]){
                width = 0;
                dfs(i,j);
                result = max(result,width);
                count++;
            }
        }
    }
    
    cout<<count<<"\n"<<result<<"\n";
    
    return 0;
}
