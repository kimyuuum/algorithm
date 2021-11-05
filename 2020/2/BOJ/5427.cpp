//
//  5427.cpp
//  
//
//  Created by 김유민 on 2020/02/23.
//

#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 1000;

char map[MAX][MAX];
bool visited[MAX][MAX] = {false,};

int w,h;
vector<pair<int,int> > flame;
int dirX[4] = {0,1,0,-1};
int dirY[4] = {-1,0,1,0};

int bfs(int x,int y){
    
    queue<pair<int,int> > q;
    q.push(make_pair(x,y));
    
    queue<pair<int,int> > fire;
    
    for(int i=0; i<flame.size(); i++){
        fire.push(flame[i]);
    }
    
    int val = 0;
    
    while(!q.empty()){
        int fsize = fire.size();
        
        for(int fs=0; fs<fsize; fs++){
            int curX = fire.front().first;
            int curY = fire.front().second;
            
            fire.pop();
            for(int i=0; i<4; i++){
                int nextX = curX + dirX[i];
                int nextY = curY + dirY[i];
                
                if(nextX >= 0 && nextX < w && nextY >= 0 && nextY < h){
                    if(map[nextX][nextY] == '.' || map[nextX][nextY] == '@'){
                        map[nextX][nextY] = '*';
                        fire.push(make_pair(nextX,nextY));
                    }
                }
            }
        }
        
        int size = q.size();
        
        for(int s=0; s<size; s++){
            int curX = q.front().first;
            int curY = q.front().second;
            q.pop();
            
            if(curX == 0 || curX == w-1 || curY == 0 || curY == h-1){
                return val + 1;
            }
            
            for(int i=0; i<4; i++){
                int nextX = curX + dirX[i];
                int nextY = curY + dirY[i];
                
                if(nextX < 0 || nextX >= w || nextY < 0 || nextY >= h)
                    continue;
                if(visited[nextX][nextY] || map[nextX][nextY] == '#' || map[nextX][nextY] == '*')
                    continue;
                q.push(make_pair(nextX,nextY));
                visited[nextX][nextY] = true;
            }
        }
        val++;
    }
    return -1;
}

int main(){
    
    int T;
    cin>>T;
    
    while(T--){
        memset(map,0,sizeof(map));
        memset(visited,false,sizeof(visited));
        flame.clear();
        
        cin>>w>>h;
        int x,y;
        string input;
        
        for(int i=0; i<h; i++){
            cin>>input;
            for(int j=0; j<w; j++){
                map[j][i] = input[j];
                if(map[j][i] == '@'){
                    x = j;
                    y = i;
                }
                else if(map[j][i] == '*'){
                    flame.push_back(make_pair(j,i));
                }
            }
        }
        
        int result = bfs(x,y);
        
        if(result == -1)
            cout<<"IMPOSSIBLE"<<"\n";
        else
            cout<<result<<"\n";
        
    }
    
    return 0;
}
