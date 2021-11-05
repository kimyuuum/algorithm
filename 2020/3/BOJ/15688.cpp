//
//  15688.cpp
//  
//
//  Created by 김유민 on 2020/03/03.
//

#include <iostream>
using namespace std;
const int MAX = 2000010;
int cnt[MAX];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n,input;
    cin>>n;
    
    for(int i=0; i<n; i++){
        cin>>input;
        cnt[input+1000000]++;
    }
    
    for(int i=0; i<2000001; i++){
        while(cnt[i]--){
            cout<<i-1000000<<"\n";
        }
    }
    
    return 0;
}
