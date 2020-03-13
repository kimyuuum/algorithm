//
//  1463.cpp
//  
//
//  Created by 김유민 on 2020/03/13.
//

#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 1000001;
int d[MAX];

int main(){
    
    int k;
    cin>>k;
    
    d[1] = 0;

    for(int i=2; i<=k; i++){
        d[i] = d[i-1] + 1;
        if(i % 3 == 0)
            d[i] = min(d[i/3]+1,d[i]);
        if(i % 2 == 0)
            d[i] = min(d[i/2]+1,d[i]);
    }
    
    cout<<d[k];
    
    return 0;
}
