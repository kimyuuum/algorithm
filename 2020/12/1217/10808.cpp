//
//  10808.cpp
//  
//
//  Created by 김유민 on 2019/12/17.
//

#include <iostream>
#include <cstring>
using namespace std;

int main(){
    
    int countArr[26] = {0,};
    string sentence;
    
    cin>>sentence;
    
    for(int i=0; i<sentence.size(); i++){
        countArr[sentence[i]- 'a']++;
    }
    
    for(int i=0; i<26; i++){
        cout<<countArr[i]<<" ";
    }
    
    return 0;
}
