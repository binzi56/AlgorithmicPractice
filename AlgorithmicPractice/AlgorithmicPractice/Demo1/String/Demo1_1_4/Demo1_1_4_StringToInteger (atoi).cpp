//
//  Demo1_1_4_StringToInteger (atoi).cpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2019/3/2.
//  Copyright © 2019 personal. All rights reserved.
//

#include "Demo1_1_4_StringToInteger (atoi).hpp"

int myAtoi(string str) {
    int index=0;
    while(str[index]==' ')index++;
    int flag=1;
    if(str[index]=='-'){
        index++;
        flag=-1;
    }else if(str[index]=='+'){
        index++;
    }
    int res=0;
    while(index < str.size()){
        if(str[index] < '0' || str[index] > '9'){
            return flag * res;
        }
        int digit=str[index]-'0';
        if(flag==1 && res*10.0+digit>=INT_MAX){
            return INT_MAX;
        }else if(flag==-1 && -(res*10.0+digit)<=INT_MIN){
            return INT_MIN;
        }
        res = res*10+digit;
        index++;
    }
    return flag*res;
}

