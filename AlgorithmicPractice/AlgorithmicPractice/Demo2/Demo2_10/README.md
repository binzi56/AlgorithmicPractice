#  两个链表的第一个公共节点(相交链表)


输入两个链表，找出它们的第一个公共节点。


解法:
```
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(headA == NULL || headB == NULL) return NULL;

    ListNode *nA = headA;
    ListNode *nB = headB;

    while(nA != nB){
        nA = ((nA == NULL) ? headB : nA->next);
        nB = ((nB == NULL) ? headA : nB->next);
    }

    return nA;
}
```
