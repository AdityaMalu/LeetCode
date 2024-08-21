class Solution {
public:
    int trap(vector<int>& height) {
        int first = 0,last = height.size()-1,ans = 0,first_h = 0,last_h = 0;
        while(first<=last){
            if(height[first] > first_h){
                first_h = height[first];
            }
            if(height[last] > last_h){
                last_h = height[last];
            }
            ans += first_h - height[first];
            ans += last_h - height[last];
            if(height[first] <= height[last]){
                first++;
            }
            else{
                last--;
            }
        }
        return ans;
    }
};