class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* nxt = nullptr;
        
        while (curr != nullptr) {
            nxt = curr->next;  
            curr->next = prev; 
            prev = curr;       
            curr = nxt;        
        }
        
        return prev;
    }
};