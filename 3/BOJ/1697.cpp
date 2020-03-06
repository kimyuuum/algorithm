//
//  1697.cpp
//  
//
//  Created by 김유민 on 2020/03/04.
//

#include <iostream>
#include <queue>
using namespace std;
const int MAX = 100000;
bool visited[MAX];
int map[MAX];
int x,k;

int bfs(){
    
    queue<int> q;
    q.push(x);
    visited[x] = true;
    int res = 1;
    
    while(!q.empty()){
        int size = q.size();
        for(int i=0; i<size; i++){
            int curX = q.front();
            q.pop();
            
            if(curX == k)
                return map[curX];
            
            for(int i=0; i<3; i++){
                int nextX;
                if(i==0)
                    nextX = curX + 1;
                if(i==1)
                    nextX = curX - 1;
                if(i==2)
                    nextX = 2 * curX;
                
                if(nextX >= 0 && nextX <= 100000){
                    if(!visited[nextX]){
                        q.push(nextX);
                        visited[nextX] = true;
                        map[nextX] = res;
                    }
                }
            }
        }
        
        res++;
    }
    
    return -1;
}

int main(){
    
    cin>>x>>k;
    int result = bfs();
    
    cout<<result;
    
    return 0;
}
