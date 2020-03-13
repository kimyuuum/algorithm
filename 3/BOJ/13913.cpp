//
//  13913.cpp
//  
//
//  Created by 김유민 on 2020/03/13.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 100001;
int x,k;
bool visited[MAX];
int road[MAX];
vector<int> v;

int bfs(){
    
    queue<pair<int,int> > q;
    q.push(make_pair(x,0));
    visited[x] = true;
    
    while(!q.empty()){
        int curX = q.front().first;
        int sec = q.front().second;
        q.pop();
        
        if(curX == k){
            int idx = curX;
            while(idx != x){
                v.push_back(idx);
                idx = road[idx];
            }
            v.push_back(x);
            return sec;
        }
        
        if(curX + 1 < MAX && !visited[curX+1]){
            q.push(make_pair(curX+1,sec+1));
            visited[curX+1] = true;
            road[curX+1] = curX;
        }
        if(curX -1 >= 0 && !visited[curX-1]){
            q.push(make_pair(curX-1,sec+1));
            visited[curX-1] = true;
            road[curX-1] = curX;
            
        }
        if(curX*2 < MAX && !visited[curX*2]){
            q.push(make_pair(curX*2,sec+1));
            visited[curX*2] = true;
            road[curX*2] = curX;
        }
    }
}

int main(){
    
    cin>>x>>k;
    int result = bfs();
    cout<<result<<"\n";
    for(int i=v.size()-1; i>=0; i--){
        cout<<v[i]<<" ";
    }
    
    return 0;
}
