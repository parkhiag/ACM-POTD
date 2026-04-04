
# Day 14

## 1. Palindrome Linked List
Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.
### Screenshot of accepted solution
<img width="1919" height="850" alt="image" src="https://github.com/user-attachments/assets/0620d24f-26ca-4dcb-b3c9-78d188341f4d" />






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
 ListNode* reversell(ListNode* head) {
    if (head==NULL || head->next==NULL) return head;
    ListNode* newhead=reversell(head->next);
    ListNode* front = head->next;
    front->next=head;
    head->next=NULL;
    return newhead;
}

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // step 1 finding the middle node
        if (head==NULL || head->next==NULL) return true;
        ListNode* slow=head;
        ListNode* fast=head;
        while (fast->next!=NULL && fast->next->next!=NULL) {
            fast=fast->next->next;
            slow=slow->next;
        }
        // slow is the middle element
        // step 2 reverse the second half of the lindked list
        ListNode* newHead= reversell(slow->next);
        // step 3 compare 1st and 2nd half. 
        ListNode* first = head;
        ListNode* second = newHead;
        while (second!=NULL) {
            if (first->val!=second->val) {
                reversell(newHead);
                return false;
            }
            
                first=first->next;
                second=second->next;
            
        }
        // reverse the list
        reversell(newHead);
        return true;



    }
};
```
---
