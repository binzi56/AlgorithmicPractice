# 5.2.7 堆排序

堆排序（`Heapsort`）是指利用堆这种数据结构所设计的一种排序算法。堆是一个近似完全二叉树的结构，并同时满足堆积的性质：即子结点的键值或索引总是小于（或者大于）它的父节点。

```
//堆排序
void heapSort(vector<int>& nums){
    // 1、无序数组nums
    // 2、将无序数组nums构建为一个大根堆
    buildMaxHeap(nums);

    // 3、交换nums[0]和nums[nums.size()-1]
    // 4、然后把前面这段数组继续下沉保持堆结构，如此循环即可
    int len = nums.size();  //此处len需要变换,单独拎出来
    for (int i = nums.size() - 1; i > 0; i--) {
        swap(nums[0], nums[i]);  // 从后往前填充值
        len--;                   // 前面的长度也减一
        heapHelper(nums, 0, len);
    }
}

// 建立大顶堆
void buildMaxHeap(vector<int>& nums){
    int length = nums.size();
    for (int i = length / 2; i >= 0; i--) {
        heapHelper(nums, i, length);
    }
}

//堆调整
void heapHelper(vector<int>& nums, int i, int length){
    int left = 2 * i + 1;  // 左节点索引(从0开始，所以左节点为i*2+1)
    int right = 2 * i + 2; // 右节点索引
    int largest = i;

    // largest保存根、左、右三者之间较大值的索引
    // 存在左节点，左节点值较大，则取左节点
    if (left < length && nums[left] > nums[largest]) {
        largest = left;
    }
    // 存在有节点，且值较大，取右节点
    if (right < length && nums[right] > nums[largest]) {
        largest = right;
    }

    // 如果非根节点较大，则继续递归
    if (largest != i) {
        swap(nums[i], nums[largest]);
        heapHelper(nums, largest, length);
    }
}
```
