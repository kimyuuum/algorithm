//
//  6593.cpp
//  
//
//  Created by 김유민 on 2020/03/03.
//

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int MAX = 30;
char map[MAX][MAX][MAX];
bool visited[MAX][MAX][MAX];
int sec[MAX][MAX][MAX] = {0,};
int l,r,c;
int dirX[6] = {0,0,1,0,-1,0};
int dirY[6] = {0,1,0,-1,0,0};
int dirZ[6] = {1,0,0,0,0,-1};

int bfs(int x,int y,int z){
    
    queue<pair<pair<int,int>,int> > q;
    q.push(make_pair(make_pair(x,y),z));
    visited[x][y][z] = true;
    int res = 1;
    while(!q.empty()){
        int size = q.size();
        for(int i=0; i<size; i++){
            int curX = q.front().first.first;
            int curY = q.front().first.second;
            int curZ = q.front().second;
            
            q.pop();
            
            if(map[curX][curY][curZ] == 'E'){
                return sec[curX][curY][curZ];
            }
            
            for(int i=0; i<6; i++){
                int nextX = curX + dirX[i];
                int nextY = curY + dirY[i];
                int nextZ = curZ + dirZ[i];
                
                if(nextX >= 0 && nextX < c && nextY >= 0 && nextY < r && nextZ >= 0 && nextZ < l){
                    if(map[nextX][nextY][nextZ] != '#' && !visited[nextX][nextY][nextZ]){
                        q.push(make_pair(make_pair(nextX,nextY),nextZ));
                        visited[nextX][nextY][nextZ] = true;
                        sec[nextX][nextY][nextZ] = res;
                    }
                }
            }
        }
        res++;
    }
    
    return -1;
}
int main(){
    
    while(1){
        memset(map,0,sizeof(map));
        memset(sec,0,sizeof(sec));
        memset(visited,0,sizeof(visited));
        
        int x,y,z;
        char input;
        cin>>l>>r>>c;
        if(l==0 && r==0 && c==0)
            break;

        for(int i=0; i<l; i++){
            for(int j=0; j<r; j++){
                for(int k=0; k<c; k++){
                    cin>>input;
                    if(input != ' ')
                        map[k][j][i] = input;
                    if(map[k][j][i] == 'S'){
                        x = k;
                        y = j;
                        z = i;
                    }
                        
                }
            }
        }

        int result = bfs(x,y,z);
        
        if(result == -1)
            cout<<"Trapped!"<<"\n";
        else
            cout<<"Escaped in "<<result<<" minute(s)."<<"\n";
        
    }
    
    
    
    return 0;
}
