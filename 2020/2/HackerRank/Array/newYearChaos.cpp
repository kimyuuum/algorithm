//
//  newYearChaos.cpp
//  
//
//  Created by 김유민 on 2020/02/25.
//

#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 100005;
int cnt[MAX];
int target[MAX];

void func(int n){
    bool isChaos = false;
    memset(cnt,0,sizeof(cnt));
    memset(target,0,sizeof(target));
    
    for(int i=0; i<n; i++){
        cin>>target[i];
    }
    
    int change = 0;
    for(int i=0; i<n; i++){
        bool isSwaped = false;
        for(int j=0; j<n-(i+1); j++){
            if(target[j] > target[j+1]){
                cnt[target[j]] += 1;
                if(cnt[target[j]] > 2){
                    cout<<"Too chaotic"<<"\n";
                    return;
                }
                int temp = target[j];
                target[j] = target[j+1];
                target[j+1] = temp;
                change++;
                isSwaped = true;
            }
        }
        if(!isSwaped)
            break;
    }
    cout<<change<<endl;
}

int main(){
    
    int n,testcase;
    cin>>testcase;
    for(int a=0; a<testcase; a++){
        cin>>n;
        func(n);
    }
    return 0;
}
