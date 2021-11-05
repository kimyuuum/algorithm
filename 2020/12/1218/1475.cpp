//
//  1475.cpp
//  
//
//  Created by 김유민 on 2019/12/18.
//

#include <iostream>
using namespace std;

int main(){
    
    int room;
    int arr[9] = {0,};
    int max=0;
    
    cin>>room;
    
    if(room == 0)
        max = 1;
    else {
        while(room != 0){
            if(room % 10 == 9)
                arr[6]++;
            else
                arr[room % 10]++;
            room /= 10;
        }
        
        if(arr[6] % 2 == 0){
            arr[6] /= 2;
        }
        else
            arr[6] = arr[6] / 2 + 1;
        
        for(int i=0; i<9; i++){
            if(max < arr[i]){
                max = arr[i];
            }
        }
    }

    cout<<max;
    
    return 0;
}
