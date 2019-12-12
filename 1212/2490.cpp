//
//  2490.cpp
//  
//
//  Created by 김유민 on 2019/12/12.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    
    int a,b,c,d;
    
    for(int i=0 ; i<3; i++){
        int count = 0;
        cin>>a>>b>>c>>d;
        count = a + b + c + d;
        
        if(count == 4)
            cout<<"E"<<"\n";
        else if(count == 3)
            cout<<"A"<<"\n";
        else if(count == 2)
            cout<<"B"<<"\n";
        else if(count == 1)
            cout<<"C"<<"\n";
        else
            cout<<"D"<<"\n";
    }
    
    return 0;
}
