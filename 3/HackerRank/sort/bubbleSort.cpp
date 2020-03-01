//
//  bubbleSort.cpp
//  
//
//  Created by 김유민 on 2020/03/01.
//

#include <iostream>
using namespace std;
const int MAX = 606;
long arr[MAX];

int main(){
    
    int n;
    cin>>n;
    
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    int swaps = 0;
    
    for(int i=0; i<n; i++){
        bool isSwap = false;
        for(int j=0; j<n-(i+1); j++){
            if(arr[j] > arr[j+1]){
                long temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                isSwap = true;
                swaps++;
            }
        }
        if(!isSwap){
            break;
        }
    }
    
    cout<<"Array is sorted in "<<swaps<<" swaps."<<"\n";
    cout<<"First Element: "<<arr[0]<<"\n";
    cout<<"Last Element: "<<arr[n-1]<<"\n";
    
    return 0;
}
