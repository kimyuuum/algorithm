//
//  makingAnagrams.cpp
//  
//
//  Created by 김유민 on 2020/02/27.
//

#include <iostream>
#include <cstring>
using namespace std;
int acnt[26];
int bcnt[26];

int main(){
    
    string a,b;
    int res = 0;
    cin>>a>>b;
    for(int i=0; i<a.size(); i++){
        acnt[a[i]-97]++;
    }
    for(int i=0; i<b.size(); i++){
        bcnt[b[i]-97]++;
    }
    
    for(int i=0; i<26; i++){
        if(acnt[i] != bcnt[i]){
            res += abs(acnt[i] - bcnt[i]);
        }
    }
    
    cout<<res;
    return 0;
}
