//
//  15664.cpp
//  
//
//  Created by 김유민 on 2020/01/25.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,num;
bool visited[8];
int arr[8];
vector<int> v;

void dfs(int count){
    
    if(count == m){
        for(int i=0; i<v.size(); i++){
            cout<<v[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    else{
        bool used[10001] = {false,};
        for(int i=0; i<n; i++){
            if(!used[arr[i]] && !visited[i]){
                if(!v.empty() && v.back() > arr[i]){
                    continue;
                }
                visited[i] = true;
                used[arr[i]] = true;
                v.push_back(arr[i]);
                dfs(count+1);
                v.pop_back();
                visited[i] = false;
            }
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
    
    return 0;
}
