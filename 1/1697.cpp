//
//  1697.cpp
//  
//
//  Created by 김유민 on 2020/01/07.
//

#include <iostream>
#include <queue>
using namespace std;

int a,b;
bool visited[100001];

int bfs(int a, int b){
    int sec=0;
    queue<int> q;
    q.push(a);

    
    while(1){
        int size = q.size();
        for(int i=0; i<size; i++){
            a = q.front();
            q.pop();
            if(a == b)
                return sec;
            if(a>0 && visited[a-1] == 0){
                q.push(a-1);
                visited[a-1] = 1;
            }
            if(a < 100000 && visited[a+1] == 0 ){
                q.push(a+1);
                visited[a+1] = 1;
            }
            if(a*2 <= 100000 && visited[2*a] == 0){
                q.push(2*a);
                visited[2*a] = 1;
            }
        }
        sec++;
    }

}

int main(){

    cin>>a>>b;
    cout<<bfs(a,b);
    
    return 0;
}
