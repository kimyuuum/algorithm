//
//  1181.cpp
//  
//
//  Created by 김유민 on 2020/03/04.
//

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct Dict{
    string word;
    int size;
};

bool comp(Dict d, Dict d2){
    if(d.size != d2.size){
        return d.size < d2.size;
    }
    else{
        return d.word < d2.word;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin>>n;
    struct Dict d[n];
    
    for(int i=0; i<n; i++){
        cin>>d[i].word;
        d[i].size = (d[i].word).size();
    }
    
    sort(d,d+n,comp);
    
    cout<<d[0].word<<"\n";
    for(int i=0; i<n; i++){
        if(i != 0 && d[i-1].word != d[i].word)
            cout<<d[i].word<<"\n";
    }
    
    return 0;
}
