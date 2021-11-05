//
//  minimumSwaps2.cpp
//  
//
//  Created by 김유민 on 2020/02/26.
//

#include <iostream>
using namespace std;
const int MAX = 100005;
int arr[MAX];
int pos[MAX];

int main(){
    
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        pos[arr[i]-1] = i;
    }
    
    int res = 0;

    for(int i=0; i<n; i++){
        if(pos[i] != i){
            int temp = arr[i];
            arr[i] = arr[pos[i]];
            arr[pos[i]] = temp;
            res++;
            pos[arr[pos[i]]-1] = pos[i];
        }
    }

    cout<<res;
    return 0;
    
}
