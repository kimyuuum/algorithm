//
//  9466_1.cpp
//  
//
//  Created by 김유민 on 2020/02/08.
//

#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 100001;

int arr[MAX];
bool visited[MAX] = {false,};
bool connected[MAX] = {false,};
int result = 0;

void dfs(int idx){
    
    int next = arr[idx];
    visited[idx] = true;
    
    if(!visited[next])
        dfs(next);
    if(visited[next] && !connected[next]){
        for(int i=next; i != idx; i = arr[i]){
            result++;
        }
        result++;
    }
    
    connected[idx] = true;
    
}

int main(){
    
    int T,n;
    cin>>T;
    
    while(T--){
        result = 0;
        memset(visited, false, sizeof(visited));
        memset(connected, false, sizeof(connected));
        cin>>n;
        for(int j=1; j<=n; j++){
            cin>>arr[j];
        }
        
        for(int k=1; k<=n; k++){
            if(!visited[k])
                dfs(k);
        }
        
        cout<<n - result<<"\n";
    }
    
    return 0;
}
