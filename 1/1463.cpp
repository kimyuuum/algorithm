//
//  1463.cpp
//  
//
//  Created by 김유민 on 2020/01/27.
//

#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 1000005;
int d[MAX];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    d[1] = 0;
    
    for(int i=2; i<=n; i++){
        d[i] = d[i-1] + 1;
        if(i % 3 == 0)
            d[i] = min(d[i],d[i/3]+1);
        if(i % 2 == 0)
            d[i] = min(d[i],d[i/2]+1);
    }
    
    cout<<d[n];
    
    return 0;
}
