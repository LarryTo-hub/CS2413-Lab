// Remove Linked List Elements - Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // Create a dummy node pointing to the original head
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Pointers for traversal
        ListNode* prev = dummy;
        ListNode* curr = head;

        // Traverse the list
        while (curr != nullptr) {
            if (curr->val == val) {
                // Unlink and potentially delete the node
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }

        // The new head is dummy->next; clean up dummy and return
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
}
