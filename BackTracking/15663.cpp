//
//  15656.cpp
//
//
//  Created by 김유민 on 2020/01/23.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[9];
int n,m,num;
bool visited[9];
vector<int> v;

void dfs(int count){
    if(count == m){
        for(int j=0; j<v.size(); j++){
            cout<<v[j]<<" ";
        }
        cout<<"\n";
        return;
    }
    bool used[10002] = {false,};
    for(int i=0; i<n; i++){
        if(!visited[i] && !used[arr[i]]){
            visited[i] = true;
            used[arr[i]] = true;
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

