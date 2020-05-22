#  旋转字符串

给定两个字符串, A 和 B。

A 的旋转操作就是将 A 最左边的字符移动到最右边。 例如, 若 A = 'abcde'，在移动一次之后结果就是'bcdea' 。如果在若干次旋转操作之后，A 能变成B，那么返回True。

示例 1:
```
输入: A = 'abcde', B = 'cdeab'
输出: true
```

示例 2:
```
输入: A = 'abcde', B = 'abced'
输出: false
```
注意：

> A 和 B 长度不超过 100。


解答:
```
bool rotateString(string A, string B) {
     return (A.size() == B.size()) && (A + A).find(B) != string::npos;
}
```
