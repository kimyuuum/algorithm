//
//  7562.cpp
//  
//
//  Created by 김유민 on 2020/02/10.
//

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int MAX = 300;

int pannel[MAX][MAX];
int visited[MAX][MAX] = {false,};
int x1,y1,x2,y2,n;

int dirX[8] = {1,2,2,1,-1,-2,-2,-1};
int dirY[8] = {2,1,-1,-2,-2,-1,1,2};

void bfs(){
    queue<pair<int,int> > q;
    q.push(make_pair(x1,y1));
    visited[x1][y1] = true;
    int count = 1;
    
    while(!q.empty()){
        
        int size = q.size();
        for(int s=0; s<size; s++){
            int curX = q.front().first;
            int curY = q.front().second;
            q.pop();
            
            if(curX == x2 && curY == y2)
                return;
            
            for(int i=0; i<8; i++){
                int nextX = curX + dirX[i];
                int nextY = curY + dirY[i];
                
                if(nextX < 0 || nextX >= n || nextY < 0 || nextY >= n)
                    continue;
                if(visited[nextX][nextY])
                    continue;
                q.push(make_pair(nextX,nextY));
                visited[nextX][nextY] = true;
                if(pannel[nextX][nextY] != 0 && pannel[nextX][nextY] < count)
                    continue;
                else
                    pannel[nextX][nextY] = count;
            }
        }
        count++;
    }
    
}

int main(){
    
    int T;
    cin>>T;
    while(T--){
        memset(pannel,0,sizeof(pannel));
        memset(visited,false,sizeof(visited));
        cin>>n;
        cin>>x1>>y1;
        cin>>x2>>y2;
        bfs();
        cout<<pannel[x2][y2]<<"\n";
    }
    
    return 0;
}
