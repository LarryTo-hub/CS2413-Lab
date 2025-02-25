// Reverse Linked List- Given the head of a singly linked list, reverse the list, and return the reversed list.

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextTemp = curr->next; // Store the next pointer
            curr->next = prev;               // Reverse the pointer
            prev = curr;                     // Move prev forward
            curr = nextTemp;                 // Move curr forward
        }

        return prev; // prev is the new head
    }
};

