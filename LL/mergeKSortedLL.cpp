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
    ListNode* mergeKLists(vector<ListNode*>& v) {
        ListNode* head;
        int minindex = v.size() + 1;
        int minval = INT_MAX;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] and v[i]->val < minval ) {
                minval = v[i]->val;
                minindex = i;
            }
        }

        if (minindex == v.size() + 1)
            return nullptr;

        head = new ListNode(v[minindex]->val);
        v[minindex] = v[minindex]->next;
        head->next = mergeKLists(v);
        return head;
    }
};