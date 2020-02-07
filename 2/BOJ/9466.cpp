//
//  9466.cpp
//  
//
//  Created by 김유민 on 2020/02/07.
//

#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 100001;
int arr[MAX];
int isTeam;

bool visited[MAX] = {false,};
bool connected[MAX] = {false,};

void dfs(int idx){
    
    int next = arr[idx];
    visited[idx] = true;
    
    if(!visited[next])
        dfs(next);
    if(visited[next] && !connected[next]){

        for(int i=next; i!= idx; i=arr[i]){
            isTeam++;
        }
        isTeam++;
        
    }
    
    connected[idx] = true;

}

int main(){
    
    int T,n;
    
    cin>>T;
    while(T--){
        isTeam = 0;
        memset(visited, false, sizeof(visited));
        memset(connected, false, sizeof(connected));

        cin>>n;
        for(int i=1; i<=n; i++){
            cin>>arr[i];
        }
        
        for(int i=1; i<=n; i++){
            if(!visited[i])
                dfs(i);
        }
        
        cout<<n - isTeam<<"\n";
    }
    
    return 0;
}

