#  复制带随机指针的链表

给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。

要求返回这个链表的 深拷贝。 

我们用一个由 n 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 [val, random_index] 表示：

* val：一个表示 Node.val 的整数。
* random_index：随机指针指向的节点索引（范围从 0 到 n-1）；如果不指向任何节点，则为  null 。


解法:
```
//方法1
Node* copyRandomList(Node* head)
{
    if (head == nullptr)
        return head;

    //遍历原链表 创建新链表节点并建立映射关系
    unordered_map<Node*, Node*> map; //key: 原链表节点  value: 新创建节点 

    Node* cur = head;
    while (cur)
    {
        map[cur] = new Node(cur->val);
        cur = cur->next;
    }

    //遍历原链表 根据map找新链表的random
    cur = head;
    while (cur)
    {
        map[cur]->next = map[cur->next];
        map[cur]->random = map[cur->random];
        cur = cur->next;
    }

    return map[head];
}

//方法2
Node* copyRandomList(Node* head) {
    if(head == NULL) return head;

    // 复制节点，紧挨到到后面
    // 1->2->3  ==>  1->1'->2->2'->3->3'
    Node *cur = head;
    while(cur != NULL){
        Node *clone = new Node(cur->val);
        clone->next = cur->next;
        cur->next = clone;
        cur = clone->next;
    }

    // 处理random指针
    cur = head;
    while(cur != NULL){
        cur->next->random = (cur->random != NULL) ? cur->random->next : NULL;
        cur = cur->next->next;
    }

    // 分离两个链表
    cur = head;
    Node *cloneRandom = cur->next;
    while(cur != NULL && cur->next != NULL){
        Node *temp = cur->next;
        cur->next = cur->next->next;
        cur = temp;
    }

    // 原始链表头：head 1->2->3
    // 克隆的链表头：cloneHead 1'->2'->3'
    return cloneRandom;
}
```
