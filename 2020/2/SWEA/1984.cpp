//
//  1984.cpp
//  
//
//  Created by 김유민 on 2020/02/04.
//

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    
    int T,num;
    int arr[10];
    cin>>T;
    
    for(int test_case=1; test_case<=T; test_case++){
        double res = 0;
        for(int i=0; i<10; i++){
            cin>>arr[i];
        }
        sort(arr,arr+10);
        
        for(int i=1; i<9; i++){
            res += (double) arr[i];
        }
        res /= 8;
        res = round(res);
        cout<<"#"<<test_case<<" "<<res<<"\n";
    }
    
    
    return 0;
}
