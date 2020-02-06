//
//  7569.cpp
//  
//
//  Created by 김유민 on 2020/02/06.
//

#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100;
int box[MAX][MAX][MAX] = {0,};
bool visited[MAX][MAX][MAX] = {false,};
int m,n,h;
queue<pair<pair<int, int>, int > > q;

int dirX[6] = {0,1,0,-1,0,0};
int dirY[6] = {-1,0,1,0,0,0};
int dirZ[6] = {0,0,0,0,1,-1};
int none = 0, day = 0;

bool checkAllRipe(){
    
    int total = (m * n * h) - none;
    int cnt = 0;
    
    for(int i=0; i<h; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                if(box[k][j][i] == 1)
                    cnt++;
            }
        }
    }
    
    return total == cnt;
    
}

void bfs(){
    
    while(!q.empty()){
        int size = q.size();
        for(int a=0; a<size; a++){
            int curX = q.front().first.first;
            int curY = q.front().first.second;
            int curZ = q.front().second;
            visited[curX][curY][curZ] = true;
            q.pop();
            
            for(int i=0; i<6; i++){
                int nextX = curX + dirX[i];
                int nextY = curY + dirY[i];
                int nextZ = curZ + dirZ[i];
                
                if(nextZ < 0 || nextZ >=h)
                    continue;
                if((nextX<0 || nextX>=m) || (nextY<0 || nextY>=n))
                    continue;
                if(visited[nextX][nextY][nextZ])
                    continue;
                if(box[nextX][nextY][nextZ] != 0)
                    continue;
                
                q.push(make_pair(make_pair(nextX,nextY),nextZ));
                visited[nextX][nextY][nextZ] = true;
                box[nextX][nextY][nextZ] = 1;
            }
        }
        day++;
    }
    
    day--;
}

int main(){
    
    cin>>m>>n>>h;
    
    for(int i=0; i<h; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                cin>>box[k][j][i];
                if(box[k][j][i] == 1){
                    q.push(make_pair(make_pair(k,j),i));
                    visited[k][j][i] = true;
                }
                else if(box[k][j][i] == -1)
                    none++;
            }
        }
    }
    
    bfs();
    
    bool isRiped = checkAllRipe();
    
    if(isRiped){
        cout<<day;
    }
    else{
        cout<<-1;
    }
    
    return 0;
}
