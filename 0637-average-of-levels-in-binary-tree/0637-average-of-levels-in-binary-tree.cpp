/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     double val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(double x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(double x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<double> averageOfLevels(TreeNode *root)
    {
        map<double, vector<double>> mp;
        vector<double> ans;
        queue<pair<TreeNode *, double>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();
            TreeNode *now = curr.first;
            double lvl = curr.second;
            mp[lvl].push_back(now->val);
            if (now->left)
                q.push({now->left, lvl + 1});
            if (now->right)
                q.push({now->right, lvl + 1});
        }

        for (auto i : mp)
        {
            double temp = accumulate(i.second.begin(), i.second.end(), 0.0) / i.second.size();
            ans.push_back(temp);
        }
        return ans;
    }
};