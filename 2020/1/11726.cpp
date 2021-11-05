//
//  11726.cpp
//  
//
//  Created by 김유민 on 2020/01/28.
//

#include <iostream>

using namespace std;

int main(){
    int n;
    int d[1001];
    cin>>n;
    
    d[1] = 1;
    d[2] = 2;
    d[3] = 3;
    d[4] = 5;
    
    for(int i=5; i<=n; i++){
        d[i] = (d[i-1] + d[i-2]) % 10007;
    }
    
    cout<<d[n];
}
