//
//  2753.cpp
//  
//
//  Created by 김유민 on 2019/12/12.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    
    int year;
    cin>>year;
    
    if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        cout<<1;
    else
        cout<<0;
    
    return 0;
}
