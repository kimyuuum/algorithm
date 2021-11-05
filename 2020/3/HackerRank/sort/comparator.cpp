//
//  comparator.cpp
//  
//
//  Created by 김유민 on 2020/03/01.
//

#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

struct Player {
    int score;
    string name;
};

class Checker{
public:
      // complete this method
    static int comparator(Player a, Player b)  {
        if(a.score > b.score){
            return 1;
        }
        else if(a.score < b.score){
            return -1;
        }
        else{
            int size = min(a.name.size(),b.name.size());
            for(int i=0; i<size; i++){
                if(a.name[i] > b.name[i])
                    return -1;
                else if(a.name[i] < b.name[i])
                    return 1;
                else
                    continue;
            }
            
            if(a.name.size() > b.name.size())
                return -1;
            else if(a.name.size() < b.name.size())
                return 1;
            else
                return 0;
        }
    }
};

