//
//  15652.cpp
//  
//
//  Created by 김유민 on 2020/01/23.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int n,m;
bool visited[9];

void dfs(int count, int index){

    if(count == m){
        for(int i=0; i<v.size(); i++){
            cout<<v[i]<<" ";
        }
        cout<<"\n";
    }

    else{
        for(int i=index; i<n; i++){
            if(!v.empty()){
                if(v.front() > i+1)
                    continue;
            }
            v.push_back(i+1);
            dfs(count+1,i);
            v.pop_back();
        }
    }
}

int main(){

    cin>>n>>m;

    dfs(0,0);

    return 0;
}
