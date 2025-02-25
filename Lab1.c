#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr != nullptr) {
            if (curr->val == val) {
                prev->next = curr->next;
                // If you're managing memory, you can delete the node:
                delete curr;
                curr = prev->next;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        ListNode* newHead = dummy->next;
        delete dummy;  // Clean up the dummy node
        return newHead;
    }
};

// Example usage for testing:
int main() {
    // Create a linked list: 1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);

    int val = 6;  // Value to remove

    Solution sol;
    ListNode* newHead = sol.removeElements(head, val);

    // Print the resulting list
    ListNode* curr = newHead;
    while (curr != nullptr) {
        std::cout << curr->val << (curr->next ? "->" : "");
        curr = curr->next;
    }
    std::cout << std::endl;

    // Free remaining nodes (if desired)
    while (newHead != nullptr) {
        ListNode* temp = newHead;
        newHead = newHead->next;
        delete temp;
    }

    return 0;
}
