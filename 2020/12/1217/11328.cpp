//
//  11328.cpp
//  
//
//  Created by 김유민 on 2019/12/17.
//

#include <iostream>
#include <cstring>
#include <list>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int num;
    bool res = true;
    string a,b;
    
    cin>>num;
    for(int i=0; i<num; i++){
        int arr[26] = {0,} ,arr2[26] = {0,};
        cin>>a>>b;
        for(int j=0; j<a.length();j++){
            arr[a[j] - 'a']++;
        }
        for(int k=0; k<b.length(); k++){
            arr2[b[k] - 'a']++;
        }
        res = true;
        for(int idx=0; idx<26; idx++){
            if(arr[idx] != arr2[idx]){
                res = false;
                break;
            }
        }
        
        if(res)
            cout<<"Possible"<<"\n";
        else
            cout<<"Impossible"<<"\n";
        
    }
    return 0;
}
