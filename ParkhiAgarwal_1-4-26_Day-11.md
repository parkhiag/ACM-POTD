
# Day 10

## 1. Merge 2 sorted lists
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.

### Screenshot of accepted solution
<img width="1919" height="856" alt="image" src="https://github.com/user-attachments/assets/392e4438-3224-43cd-982b-c95eb3cfae22" />





### Code
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dnode = new ListNode(-1);
        ListNode* temp = dnode;
        ListNode* t1 = list1;
        ListNode* t2 = list2;
        while (t1 != NULL && t2 != NULL) {
            if (t1->val <= t2->val) {
                temp->next = t1;
                temp = t1;
                t1 = t1->next;
            } else {
                temp->next = t2;
                temp = t2;
                t2 = t2->next;
            }
        }
        if (t1 == NULL) {
            temp->next = t2;
        } else {
            temp->next = t1;
        }
        return dnode->next;
    }
};
```
---
