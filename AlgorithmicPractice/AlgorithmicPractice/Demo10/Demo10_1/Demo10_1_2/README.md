#  不用加减乘除做加法

写一个函数，求两个整数之和，要求在函数体内不得使用 “+”、“-”、“*”、“/” 四则运算符号。


示例:
```
输入: a = 1, b = 1
输出: 2
```

提示：

* a, b 均可能是负数或 0
* 结果不会溢出 32 位整数

解法:
```
int add(int a, int b) {
    while(b != 0)  //b==0说明已经无法进位了
    {
        int temp = (a ^ b);  // 异或操作得无进位和
        b = ((unsigned int)(a & b) << 1);  //与操作后得进位值，注意：C++不支持负值左移！！这里要加上unsigned int
        a = temp;
    }
    return a;
}
```


[位运算_面试题65. 不用加减乘除做加法](https://leetcode-cn.com/problems/bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof/solution/wei-yun-suan-_mian-shi-ti-65-bu-yong-jia-jian-chen/)
