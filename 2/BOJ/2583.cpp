//
//  2583.cpp
//
//
//  Created by 김유민 on 2020/02/10.
//

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 100;
int box[MAX][MAX] = {0,};
bool visited[MAX][MAX] = {false,};
int n,m,k;
int area = 0;
queue<pair<int,int> > q;
vector<int> v;

int dirX[4] = {0,1,0,-1};
int dirY[4] = {1,0,-1,0};

void bfs(int x,int y){
    
    int width = 0;
    q.push(make_pair(x,y));
    visited[x][y] = true;
    
    while(!q.empty()){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nextX = curX + dirX[i];
            int nextY = curY + dirY[i];
            
            if( 0 > nextX || nextX >= n || nextY < 0 || nextY >= m)
                continue;
            if(visited[nextX][nextY] || box[nextX][nextY] == 1)
                continue;
            q.push(make_pair(nextX,nextY));
            visited[nextX][nextY] = 1;
        }
        width++;
    }
    
    v.push_back(width);
    
}

int main(){
    
    cin>>m>>n>>k;
    
    for(int a=0; a<k; a++){

        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        
        for(int i=y1; i<y2; i++){
            for(int j=x1; j<x2; j++){
                box[j][i] = 1;
            }
        }
    }
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(box[j][i] == 0 && !visited[j][i]){
                bfs(j,i);
                area++;
            }
        }
    }
    
    cout<<area<<"\n";
    sort(v.begin(),v.end());
    
    for(int i=0; i<v.size()-1; i++){
        cout<<v[i]<<" ";
    }
    cout<<v[v.size()-1];
    
    return 0;
}
