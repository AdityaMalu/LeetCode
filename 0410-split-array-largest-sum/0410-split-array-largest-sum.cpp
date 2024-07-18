class Solution {
public:
    int check(vector<int> & nums, int num){
        int req = 1,temp = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            temp += nums[i];
            if(temp>num){
                req++;
                temp = nums[i];
            }
        }
        return req;
    }
    int splitArray(vector<int>& nums, int k) {
        int start = *max_element(nums.begin(),nums.end());
        int end = accumulate(nums.begin(),nums.end(),0);

        while(start<end){
            int mid = (start+end)>>1;
            if(check(nums,mid) > k){
                start = mid+1;
            }
            else{
                end = mid;
            }
        }
        return start;

    }
};