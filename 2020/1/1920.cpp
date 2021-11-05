//
//  1920.cpp
//  
//
//  Created by 김유민 on 2020/01/28.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int arr[100001];
    int n,m,a;
    cin>>n;
    
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    
    cin>>m;
    
    for(int i=0; i<m; i++){
        cin>>a;
        int exist = 0;
        int start = 0;
        int end = n-1;
        while(start <= end){
            int mid = (start + end) /2;
            if(a > arr[mid]){
                start = mid + 1;
            }
            else if(a < arr[mid]){
                end = mid - 1;
            }
            else{
                exist = 1;
            }
        }
        cout<<exist<<"\n";
    }
    return 0;
}
