/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head, *fast = head;
        if(head == nullptr) return false;
        if (head->next == nullptr){
            return false;
        }
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            if(fast == slow){
                return true;
            }
            slow = slow->next;
        }
        return false;
    }
};