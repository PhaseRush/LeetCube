// 19. Remove Nth Node From End of List (Medium)

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    /**
        Given the head of a linked list, remove the nth node from the end of the list and return its head.

        @pre The number of nodes in the list is sz.
        @pre 1 <= sz <= 30
        @pre 0 <= Node.val <= 100
        @pre 1 <= n <= sz
    */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first = head, *second = head;

        for (int i = 0; i < n; ++i) second = second->next;

        if (!second) {
            ListNode* temp = head->next;
            delete head;
            return temp;
        }

        while (second->next) {
            first = first->next;
            second = second->next;
        }

        ListNode* temp = first->next;
        first->next = temp->next;
        delete temp;
        return head;
    }
};