//
//  2493.cpp
//  
//
//  Created by 김유민 on 2019/12/26.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main(){
    
    int num;
    int top;
    bool isZero = false;
    cin>>num;
    
    int arr[num];
    
    for(int i=0; i<num; i++){
        cin>>top;
        arr[i] = top;
    }
    
    v.push_back(0);
    
    for(int i=1; i<num; i++){
        isZero = false;
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
