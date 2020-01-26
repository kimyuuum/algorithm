//
//  1759.cpp
//  
//
//  Created by 김유민 on 2020/01/26.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int l,c;
char pass;
char arr[15];
bool visited[15];
vector<char> v;

void dfs(int count,int collection,int noncollection){
    
    if(count == l){
        if(noncollection >= 2 && collection >= 1){
            for(int i=0; i<v.size(); i++){
                cout<<v[i];
            }
            cout<<"\n";
        }
    }
    else{
        for(int i=0; i<c; i++){
            if(!v.empty() && v.back() > arr[i])
                continue;
            if(visited[i] == true)
                continue;
            visited[i] = true;
            v.push_back(arr[i]);
            if(arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u'){
                dfs(count+1,collection+1,noncollection);
            }
            else{
                dfs(count+1,collection,noncollection+1);
            }
            v.pop_back();
            visited[i] = false;
        }
    }
}

int main(){
    
    cin>>l>>c;
    for(int i=0; i<c; i++){
        cin>>pass;
        arr[i] = pass;
    }
    sort(arr,arr+c);
    dfs(0,0,0);
    
    return 0;
}
