//
//  15654.cpp
//  
//
//  Created by 김유민 on 2020/01/23.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,num;
vector<int> v;
int arr[9];
bool visited[9];

void dfs(int count){
    
    if(count == m){
        for(int i=0; i<v.size(); i++){
            cout<<v[i]<<" ";
        }
        cout<<"\n";
    }
    else{
        for(int i=0; i<n; i++){
            if(visited[i] == true)
                continue;
            visited[i] = true;
            v.push_back(arr[i]);
            dfs(count+1);
            v.pop_back();
            visited[i] = false;
        }
    }
}
int main(){
    
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>num;
        arr[i] = num;
    }
    sort(arr,arr+n);

    dfs(0);
    
}
