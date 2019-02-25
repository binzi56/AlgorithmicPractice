# 5.2.4 希尔排序

希尔排序(Shell's Sort)是插入排序的一种又称“缩小增量排序”（Diminishing Increment Sort），是直接插入排序算法的一种更高效的改进版本。希尔排序是非稳定排序算法。该方法因D.L.Shell于1959年提出而得名。
希尔排序是把记录按下标的一定增量分组，对每组使用直接插入排序算法排序；随着增量逐渐减少，每组包含的关键词越来越多，当增量减至1时，整个文件恰被分成一组，算法便终止。

```
//希尔排序
void shellSort(vector<int>& nums, int n){
    int temp;
    int gap = n;
    do{
        gap = gap / 3 + 1;
        for (int i = gap; i < n; i++)
        {
            if (nums[i] < nums[i - gap]){
                temp = nums[i];
                int j;
                for (j = i; j >= gap && temp < nums[j - gap]; j -= gap){
                    nums[j] = nums[j - gap];
                }
                nums[j] = temp;
            }
        }
    } while (gap > 1);
}
```
