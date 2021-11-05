//
//  2071.cpp
//  
//
//  Created by 김유민 on 2020/02/02.
//

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    
    int testcase;
    float num;
    cin>>testcase;
    for(int i=1; i<=testcase; i++){
        float avg = 0;
        for(int j=0; j<10; j++){
            cin>>num;
            avg += num;
        }
        avg /= 10;
        avg = roundf(avg);
        cout<<"#"<<i<<" "<<avg<<"\n";
    }
    
    return 0;
}
