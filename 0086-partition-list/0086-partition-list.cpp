class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* greaterList = new ListNode(0);
        ListNode* lessList = new ListNode(0);
        ListNode* greaterListHead = greaterList;
        ListNode* lessListHead = lessList;
        ListNode* temp = head;
        
        while (temp) {
            if (temp->val < x) {
                lessList->next = temp;
                lessList = lessList->next;
            } else {
                greaterList->next = temp;
                greaterList = greaterList->next;
            }
            temp = temp->next;
        }
        
        greaterList->next = nullptr; 
        lessList->next = greaterListHead->next; 
        
        head = lessListHead->next;
        
        delete greaterListHead;
        delete lessListHead;
        
        return head;
    }
};