
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

## 2. Rotate Linked List
Given the head of a linked list, rotate the list to the right by k places.

### Screenshot of accepted solution
<img width="1919" height="854" alt="image" src="https://github.com/user-attachments/assets/a3033e97-9545-42cf-abfd-51a29a067f37" />


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
    ListNode* rotateRight(ListNode* head, int k) {
        // we find length. k=k%n. connect head to tail. find the new tail. tail->next=newhead. break cycle
        if (!head || !head->next || k == 0) return head;
        ListNode* temp=head;
        int n=1;
        while (temp->next!=NULL) {
            temp=temp->next;
            n++;
        }

        k=k%n;
        if (k==0) return head; // no rotation

        ListNode* tail=temp;
        tail->next=head;

        // newtail will be at n-k from head;
        ListNode* newTail= head;
        for (int i=0; i<n-k-1; i++) {
            newTail=newTail->next;
        }

        ListNode* newHead= newTail->next;
        newTail->next=NULL;
        
        return newHead;

    }
};
```

### Notes/Thought process
first thought was how i solved rotate array bu k places. in that we reverse the array then reverse first k places and then reverse the remaining k places. and then thought about how to reverse the linked list. but a simpler way to do this would be to simply connect the whole linked list and then find out what will be the new head and at which position i have to break the linked list. 

---
