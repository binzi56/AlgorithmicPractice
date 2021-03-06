# 5.2.2 选择排序

选择排序（Selection sort）是一种简单直观的排序算法。它的工作原理是每一次从待排序的数据元素中选出最小（或最大）的一个元素，存放在序列的起始位置，然后，再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。以此类推，直到全部待排序的数据元素排完。 选择排序是不稳定的排序方法。

```c++
//选择排序
void selectSort(vector<int>& nums, int n){
    for (int i = 0; i < n; i++){
        int min = i;
        for (int j = i + 1; j < n ; j++) {
            if (nums[j] < nums[min]){
                min = j;
            }
        }
        
        if (min != i){
            __swap(nums[i],nums[min]);
        }
    }
}
```

选择排序法的第一层循环从起始元素开始选到倒数第二个元素，主要是在每次进入的第二层循环之前，将外层循环的下标赋值给临时变量，接下来的第二层循环中，如果发现有比这个最小位置处的元素更小的元素，则将那个更小的元素的下标赋给临时变量，最后，在二层循环退出后，如果临时变量改变，则说明，有比当前外层循环位置更小的元素，需要将这两个元素交换.
