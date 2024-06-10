class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0 , j = height.size()-1, ans = 0;
        while(j > i){
            ans = max(ans,(j-i)*min(height[j],height[i]));
            if(height[j] > height[i]){
                i++;
            }
            else{
                j--;
            }
        }
        return ans;
    }
};