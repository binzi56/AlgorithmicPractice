//
//  CommonTools.cpp
//  AlgorithmicPractice
//
//  Created by 帅斌 on 2018/9/26.
//  Copyright © 2018年 personal. All rights reserved.
//

#include "CommonTools.hpp"

template <typename T> void printfArr (vector<T>& arr){
    printf("============Array============\nArray[\n");
    for (int i = 0; i < arr.size(); i++) {
        if (typeid(arr[i]) == typeid(int)) {
            printf("%8d", arr[i]);
        }else if (typeid(arr[i]) == typeid(char)){
            printf("%8c", arr[i]);
        }else if (typeid(arr[i]) == typeid(string)){
            printf("%8s", arr[i]);
        }
        if (i < arr.size() - 1) {
            printf(",");
        }
        printf("\n");
    }
    printf("%6]\n============Array============");
}

void printfIntArr (vector<int>& arr){
//    printf("============Array============\nArray:[");
    printf("Array:[");
    for (int i = 0; i < arr.size(); i++) {
        if (i < arr.size() - 1) {
            printf("%d,", arr[i]);
        }else{
            printf("%d]\n", arr[i]);
        }
    }
//    printf("============Array============\n");
}
