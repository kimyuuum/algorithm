//
//  1919.cpp
//  
//
//  Created by 김유민 on 2019/12/19.
//

#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string input;
    int count = 0;
    int arr1[26] = {0,};
    int arr2[26] = {0,};
    
    cin>>input;
    for(int j=0; j<input.length(); j++){
        arr1[input[j] - 'a']++;
    }
    
    cin>>input;
    for(int i=0; i<input.length(); i++){
        arr2[input[i] - 'a']++;
    }
    
    for(int i=0; i<26; i++){
        if(arr1[i] != arr2[i])
            count += abs(arr1[i] - arr2[i]);
    }
        
    cout<<count<<"\n";
    
    return 0;
}
