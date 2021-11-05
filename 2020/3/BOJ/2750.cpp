//
//  2750.cpp
//  
//
//  Created by 김유민 on 2020/03/03.
//

#include <iostream>
using namespace std;
const int MAX = 1005;
int arr[MAX];

void quick_sort(int start, int end){
    if(end - start <= 1)
        return;
    int pivot = arr[start];
    int l = start + 1;
    int r = end-1;
    
    while(1){
        while(l <= r && arr[l] <= pivot){
            l++;
        }
        while(r >= l && arr[r] >= pivot)
            r--;
        if(l>r)
            break;
        swap(arr[l],arr[r]);
    }
    swap(arr[r],arr[start]);
    
    quick_sort(start,r);
    quick_sort(r+1,end);
    
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin>>n;
    
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    quick_sort(0,n);
        
    for(int i=0; i<n-1; i++){
        cout<<arr[i]<<" ";
    }
    cout<<arr[n-1];
    return 0;
}
