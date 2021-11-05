//
//  10814.cpp
//  
//
//  Created by 김유민 on 2020/03/04.
//

#include <iostream>
#include <algorithm>
using namespace std;

struct Member{
    int age;
    string name;
    int idx;
};

bool comp(Member m1, Member m2){
    if(m1.age == m2.age){
        return m1.idx < m2.idx;
    }
    else{
        return m1.age < m2.age;
    }
}

int main(){
    
    int n;
    cin>>n;
    struct Member m[n];
    
    for(int i=0; i<n; i++){
        cin>>m[i].age>>m[i].name;
        m[i].idx = i;
    }
    
    sort(m,m+n,comp);
    
    for(int i=0; i<n; i++){
        cout<<m[i].age<<" "<<m[i].name<<"\n";
    }
    
    return 0;
}
