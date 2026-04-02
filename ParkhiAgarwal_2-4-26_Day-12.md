
# Day 11

## 1. Remove Duplicates from Sorted List
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

### Screenshot of accepted solution
<img width="1919" height="852" alt="image" src="https://github.com/user-attachments/assets/81a89b2d-746f-4baa-82da-9f6adf5e9afa" />






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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head==NULL || head->next==NULL) return head;
        ListNode* curr=head;
        while (curr!=NULL && curr->next!=NULL) {
            if (curr->val==curr->next->val) {
                ListNode* temp=curr->next;
                curr->next=temp->next;
                delete temp;
            }
            else {
                curr=curr->next;
            }
        }
        return head;
    }
};
```
### Note for self
took 26 mins bcz i first started with 2 pointer logic and later realised it is just complicating the code.


---
