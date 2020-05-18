//
//  Demo1_1_6_addBinary.cpp
//  AlgorithmicPractice
//
//  Created by shuaibin on 2020/5/17.
//  Copyright © 2020 personal. All rights reserved.
//

#include "Demo1_1_6_addBinary.hpp"

string addBinary(string a, string b) {
    string s;
    s.reserve(a.size() + b.size());
    int c = 0, i = a.size() - 1, j = b.size() - 1;
    while(i >= 0 || j >= 0 || c == 1)
    {
        c += i >= 0 ? a[i--] - '0' : 0;
        c += j >= 0 ? b[j--] - '0' : 0;
        s.push_back((c & 1) + '0');
        c >>= 1;
    }
    reverse(s.begin(), s.end());
    return s;
}



/*
 从a、b的最后一位开始（因为至少有一位所以这样就是对齐的），三目运算符判断是否已经向前遍历完了当前a或b字符串，如果遍历完了（i或j为0）那么为空，给0，不然给本位字符与0的ASCII值相减的结果也就是0或1的数值。 每循环一次就把a和b给的值加到c中去，用位与操作c&1取c的二进制最后一位（0或1）加0的ASCII值变回字符，然后这个字符就是结果字符串的当前位。然后c右移1位完成二进制的进位操作（值相当于十进制下除以2，也就是让c=进位后的下一位），保存当前的下一位结果，然后进行下一次的针对下一位的运算。 此时如果前面的运算进位了，c就会是1，如果前面的运算没进位，那么c就会是0。 PS：循环判断里判断c是否为1的条件就是因此而生的，操作到最后如果最后第二次循环有进位，那么i=0,j=0,c=1，此时要再循环一遍这样才能把1放进结果字符串里的最后一位，也就是翻转后的最高位。（所以从这个逻辑上讲，一开始的reserve空间开大了……应该是只要a、b两者中的最长者的长度加1即可，毕竟两个N进制数之和的位数最多是原有最大位数加1）
 
 */
