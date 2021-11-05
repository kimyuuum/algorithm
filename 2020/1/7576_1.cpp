//
//  7576_1.cpp
//  
//
//  Created by 김유민 on 2020/01/27.
//

#include <iostream>
#include <queue>
using namespace std;

const int MAX = 1001;
int tomato[MAX][MAX] = {-1,};
int m,n,none=0;
int dirX[4] = {0,1,0,-1};
int dirY[4] = {-1,0,1,0};
queue<pair<int,int> > q;

bool allRipe(){
    int possible = m*n - none;
    int count = 0;
    for(int i=0; i<m; i++){
        for(int j=0; jwn; j++){
            if(tomato[i][j] == 1)
                count++;
        }
    }
    return possible == count;
}

int bfs(){
    int day = 0;
    if(q.empty()){
        return -1;
    }
    
    while(!q.empty()){
        int size = q.size();
        
        for(int i=0; i<size; i++){
            int curX = q.front().first;
            int curY = q.front().second;
            
            for(int i=0; i<4; i++){
                int nextX = curX + dirX[i];
                int nextY = curY + dirY[i];
                
                if(nextX >= 0 && nextX < m && nextY >= 0 && nextY < n){
                    if(tomato[nextX][nextY] == 0){
                        q.push(make_pair(nextX,nextY));
                        tomato[nextX][nextY] = 1;
                    }
                }
            }
            q.pop();
            if(q.size() == 0 && allRipe())
                return day;
            else if(!allRipe() && q.size() == 0)
                 return -1;
        }
        day++;
    }
}

int main(){
    
    cin>>n>>m;
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>tomato[i][j];
            if(tomato[i][j] == 1)
                q.push(make_pair(i,j));
            else if(tomato[i][j] == -1)
                none++;
        }
    }
    
    if(m*n-none == q.size()){
        cout<<0<<"\n";
    }
    else{
        cout<<bfs()<<"\n";
    }
    
    return 0;
}
