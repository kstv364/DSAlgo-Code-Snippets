class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *fast, *slow;
        fast = slow = head;
        while (fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast) slow = slow->next;
        slow = reverse(slow);
        ListNode * curr = head;
        while (slow) {
            if (slow->val != curr->val)
                return false;
            slow = slow->next;
            curr = curr->next;
        }
        return true;
    }

    ListNode* reverse(ListNode * head) {
        ListNode *curr = head, *next, *prev = NULL;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};