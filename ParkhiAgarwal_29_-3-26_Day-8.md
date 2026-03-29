
# Day 8

## 1. Rotate Linked List
Given the head of a singly linked list, reverse the list, and return the reversed list.

### Screenshot of accepted solution
<img width="1919" height="858" alt="image" src="https://github.com/user-attachments/assets/cc49fcef-9ff9-4ee2-912d-9baa8daf135e" />



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
    ListNode* reverseList(ListNode* head) {
        stack<ListNode*> st;
        if (head==NULL) return NULL;
        ListNode* node=head;

        while (node!=NULL) {
            st.push(node);
            node=node->next;
        }

        head = st.top();
        st.pop();
        node=head;

        while (!st.empty()) {
            node->next = st.top();
            st.pop();
            node=node->next;
        }
        node->next=NULL;

        return head;
    }
};
```
---
