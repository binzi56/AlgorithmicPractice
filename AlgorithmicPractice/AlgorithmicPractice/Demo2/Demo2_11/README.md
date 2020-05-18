#  复制带随机指针的链表

给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。

要求返回这个链表的 深拷贝。 

我们用一个由 n 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 [val, random_index] 表示：

* val：一个表示 Node.val 的整数。
* random_index：随机指针指向的节点索引（范围从 0 到 n-1）；如果不指向任何节点，则为  null 。


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
Node* copyRandomList(Node* head)
{
    if (head == nullptr)
        return head;

    //遍历原链表 遍历过程中插入新副本节点
    Node* cur = head;
    while (cur)
    {
        Node* node = new Node(cur->val);
        Node* next = cur->next;
        node->next = next;
        cur->next = node;
        cur = next;
    }

    //遍历原链表 对新副本节点设置random指针
    cur = head;
    while (cur)
    {
        cur->next->random = cur->random ? cur->random->next : nullptr;
        cur = cur->next->next;
    }

    //分离出原链表与新副本链表
    cur = head;
    Node* new_cur = head->next;
    Node* res = new_cur;
    while (cur)
    {
        cur->next = cur->next->next;
        cur = cur->next;

        new_cur->next = cur ? cur->next : nullptr;
        new_cur = new_cur->next;
    }

    return res; //注意：不能再返回head->next了，head已经是分离后的原链表
}
```
