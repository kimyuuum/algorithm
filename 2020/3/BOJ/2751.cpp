//
//  2751.cpp
//  
//
//  Created by 김유민 on 2020/03/03.
//

#include <iostream>
using namespace std;
const int MAX = 1000010;
int arr[MAX];
int temp[MAX];

void merge(int start,int end){
    
    int mid = (start + end) /2;
    int aIdx = start;
    int bIdx = mid;
    int idx = start;

    while(aIdx < mid && bIdx < end){
        if(arr[aIdx] > arr[bIdx]){
            temp[idx++] = arr[bIdx++];
        }
        else{
            temp[idx++] = arr[aIdx++];
        }
    }
    
    while(aIdx < mid){
        temp[idx++] = arr[aIdx++];
    }
    while(bIdx < end){
        temp[idx++] = arr[bIdx++];
    }
    
    for(int i = start; i<end; i++){
        arr[i] = temp[i];
    }
    
}

void merge_sort(int start,int end){
    
    int size = end - start;
    if(size == 1)
        return;
    if(size == 2){
        if(arr[start] > arr[start+1]){
            int temp = arr[start];
            arr[start] = arr[start+1];
            arr[start+1] = temp;
        }
        return;
    }
    
    int mid = (start + end) / 2;
    merge_sort(start,mid);
    merge_sort(mid,end);
    merge(start,end);
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin>>n;
    
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    merge_sort(0,n);
    
    for(int i=0; i<n-1; i++){
        cout<<arr[i]<<" ";
    }
    cout<<arr[n-1];
    
    return 0;
}
