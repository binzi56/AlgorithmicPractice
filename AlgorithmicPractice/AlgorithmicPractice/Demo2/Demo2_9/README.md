#  链表中倒数第k个节点



输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。例如，一个链表有6个节点，从头节点开始，它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个节点是值为4的节点。

 

示例：
```
给定一个链表: 1->2->3->4->5, 和 k = 2.

返回链表 4->5.
```



解法:
```
//快慢指针
ListNode* getKthFromEnd(ListNode* head, int k) {
    ListNode* fast = head;
    ListNode* low = head;
    while (fast != NULL) {
        fast = fast->next;
        if (k == 0) {
            low = low->next;
        } else {
            k--;
        }
    }
    return low;        
}

//递归
ListNode* getKthFromEnd1(ListNode* head, int k) {
    int pos = 0;
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if (head == NULL) {
            return 0;
        }
        ListNode* ret = getKthFromEnd(head->next, k);
        pos++;
        if (pos == k) {
            return head;
        }
        return ret;    
    }
}


ListNode* getKthFromEnd(ListNode* head, int k) {
     if(head == NULL) return head;

     ListNode *pre = head;
     ListNode *cur = head;
     for(int i = 0; i < k; i++){
         pre = pre->next;
     }

     if(pre == NULL) return head;

     while(pre != NULL){
         pre = pre->next;
         cur = cur->next;
     }

     return cur;
}
```

