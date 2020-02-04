//
//  2493.cpp
//  
//
//  Created by 김유민 on 2020/02/04.
//

#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    int n;
    cin>>n;
    int arr[n];
    
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    vector<int> v;
    v.push_back(0);
    
    bool isZero = false;
    
    for(int i=1; i<n; i++){
        for(int j=i-1; j>=0; j--){
            if(arr[j] >= arr[i]){
                v.push_back(j+1);
                isZero = false;
                break;
            }
            else{
                isZero = true;
            }
        }
        if(isZero)
            v.push_back(0);
    }
    
    for(int i=0; i<v.size()-1; i++){
        cout<<v[i]<<" ";
    }
    cout<<v[v.size()-1];
    return 0;
}
