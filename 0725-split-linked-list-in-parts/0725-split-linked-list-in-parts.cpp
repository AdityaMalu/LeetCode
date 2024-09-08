class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int cnt = 0;
        vector<ListNode*> ans(k, nullptr);

        ListNode* temp = head;
        while (temp) {
            cnt++;
            temp = temp->next;
        }

        int partSize = cnt / k;
        int rem = cnt % k;

        temp = head;
        for (int i = 0; i < k && temp; ++i) {
            ans[i] = temp;
            int div = partSize + (rem-- > 0 ? 1 : 0);
            for (int j = 1; j < div; ++j) {
                temp = temp->next;
            }

            ListNode* next = temp->next;
            temp->next = nullptr;
            temp = next;
        }

        return ans;
    }
};
