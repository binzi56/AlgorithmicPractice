#  K个一组翻转链表

给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。

如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

示例：

给你这个链表：1->2->3->4->5

当 k = 2 时，应当返回: 2->1->4->3->5

当 k = 3 时，应当返回: 3->2->1->4->5

 

说明：
- 你的算法只能使用常数的额外空间。
- 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。

解法：
```c
ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == NULL) return NULL;
    ListNode *a = head;
    ListNode *b = head;
    for (int i = 0; i < k; i++) {
        if (b == NULL) return head;
        b = b->next;
    }

    ListNode *newNode = reverseOperator(a,b); //反转前k个节点
    a->next = reverseKGroup(b,k);             //接上后面反转的节点
    return newNode;
}

ListNode* reverseOperator(ListNode* n,ListNode *b) {
    ListNode *pre = NULL, *cur = n, *nxt = n;
    while (cur != b) {
        nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    }
    return pre;
}
```

