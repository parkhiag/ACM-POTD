# Day 13

## 1. Intersection of two linked list
Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.
### Screenshot of accepted solution
<img width="1919" height="854" alt="image" src="https://github.com/user-attachments/assets/10b9ae29-6ee5-4608-8426-a17de72a13bf" />






### Code
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1= headA;
        ListNode* temp2= headB;

        while (temp1!=temp2) {
            if (temp1==NULL) temp1=headB;
            else temp1=temp1->next;

            if (temp2==NULL) temp2=headA;
            else temp2=temp2->next;
        }

        return temp2;

    }
};
```
---
