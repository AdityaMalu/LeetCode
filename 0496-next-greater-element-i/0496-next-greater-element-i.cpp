class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        unordered_map<int, int> mp; 
        vector<int> ans;  

        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!stk.empty() && stk.top() <= nums2[i]) {
                stk.pop();
            }
            
            if (stk.empty()) {
                mp[nums2[i]] = -1;
            } else {
                mp[nums2[i]] = stk.top();
            }
            
            stk.push(nums2[i]);
        }

        for (auto num : nums1) {
            ans.push_back(mp[num]);
        }

        return ans;
    }
};
