//
//  13300.cpp
//  
//
//  Created by 김유민 on 2019/12/19.
//

#include <iostream>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int student,max,gender,year;
    int room=0;
    int girl[6] = {0,};
    int boy[6] = {0,};
    
    cin>>student>>max;
    
    for(int i=0; i<student; i++){
        cin>>gender>>year;
        if(gender == 0){
            girl[year-1]++;
        }
        else if(gender == 1){
            boy[year-1]++;
        }
    }
    
    for(int i=0; i<6; i++){
        if(girl[i] != 0){
            if(girl[i] < max)
                room++;
            else if(girl[i] >= max){
                if(girl[i] % max == 0)
                    room += girl[i] / max;
                else
                    room += girl[i] / max + 1;
            }
        }
        if(boy[i] != 0){
            if(boy[i] < max)
                room++;
            else if(boy[i] >= max){
                if(boy[i] % max == 0)
                    room += boy[i] / max;
                else
                    room += boy[i] / max + 1;
            }
        }
    }
    
    cout<<room;
    
    return 0;
}
