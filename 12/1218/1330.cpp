//
//  1330.cpp
//  
//
//  Created by 김유민 on 2019/12/18.
//

#include <iostream>
using namespace std;

int main(){
    
    int a,b;
    cin>>a>>b;
    
    if(a>b)
        cout<<">"<<endl;
    else if(a<b)
        cout<<"<"<<endl;
    else
        cout<<"=="<<endl;
    
    return 0;
}
