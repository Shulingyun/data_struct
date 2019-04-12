# LeetCode 24 

### 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

![](/home/sly/文档/ARTS打卡/第一周/LeetCode24.jpg)

```c
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *p, *q, ret;
    ret.next = head;
    p = &ret;
    q = head;
    while (q && q->next) {//判断链表是否为空
        p->next = q->next;
        q->next = p->next->next;
        p->next->next = q;
        p = q;
        q = q->next;
    }
    return ret.next;
}
```

