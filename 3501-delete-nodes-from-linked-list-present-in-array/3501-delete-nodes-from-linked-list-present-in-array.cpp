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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* curr = head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        unordered_set<int> s;
        for(auto i : nums){
            s.insert(i);
        }

        while(curr){
            if(s.find(curr->val) != s.end()){
                prev->next = curr->next;
            }
            else{
                prev = curr;
            }
            curr = curr->next;
        }
        return dummy->next;
    }
};