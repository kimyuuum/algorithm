//
//  7576.cpp
//  
//
//  Created by 김유민 on 2020/01/08.
//

#include <iostream>
#include <queue>
using namespace std;

const int MAX = 1001;

int m,n;

int box[MAX][MAX] = {-1,};
int check[MAX][MAX] = {-1,};
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int none = 0;
queue<pair<int,int> > q;

bool allDone(){
    
    int pos = m*n - none;
    int cnt = 0;
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(box[i][j] == 1)
                cnt++;
        }
    }
    
    return pos == cnt;
}

int bfs(){
    int day = 0;
    
    if(q.empty())
        return -1;
    
    while(!q.empty()){
        int size = q.size();
        
        for(int i=0; i<size; i++){
            int x = q.front().first;
            int y = q.front().second;

            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(0 <= nx && nx < m && 0<= ny && ny < n){
                    if(box[nx][ny] == 0){
                        box[nx][ny] = 1;
                        q.push(make_pair(nx,ny));
                    }
                }
            }
            q.pop();
            
            if(q.size() == 0 && allDone())
                return day;
            else if(q.size() == 0 && !allDone())
                return -1;
        }
        day++;
    }
}

int main(){
    
    cin>>n>>m;
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>box[i][j];
            
            if(box[i][j] == 1)
                q.push(make_pair(i,j));
            else if(box[i][j] == -1)
                none++;
        }
    }
    
    if(q.size() == m*n - none){
        cout<<0<<"\n";
    }
    else{
        cout<<bfs()<<"\n";
    }
    
    return 0;
}
