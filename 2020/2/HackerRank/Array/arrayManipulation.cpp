//
//  arrayManipulation.cpp
//  
//
//  Created by 김유민 on 2020/02/26.
//

#include <iostream>
using namespace std;
const long MAX = 10000006;
long arr[MAX] = {0,};

int main(){
    
    int n,m;
    cin>>n>>m;
    int a,b,k;
    long res = 0;
    long max = 0;
    for(int t=0; t<m; t++){
        cin>>a>>b>>k;
        arr[a] += k;
        if(b+1 <= n)
            arr[b+1] -= k;
    }

    for(long i=1; i<=n; i++){
        res += arr[i];
        if(max < res)
            max = res;
    }
    cout<<max;
    return 0;
}
