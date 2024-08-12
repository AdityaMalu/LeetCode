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
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *one = list1, *two = list2, *dummy = new ListNode(-1),
                 *dummy2 = dummy;

        while (one && two)
        {
            if (one->val > two->val)
            {
                dummy->next = two;
                two = two->next;
            }
            else
            {
                dummy->next = one;
                one = one->next;
            }
            dummy = dummy->next;
        }
        if (one)
        {
            dummy->next = one;
        }
        else
        {
            dummy->next = two;
        }

        return dummy2->next;
    }
};