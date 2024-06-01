class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int all_xor = 0;
        for(auto i: nums){
            all_xor ^= i;
        } 
        int group_one = 0;
        int group_two = 0;

        int bit_pos_diff = 0;

        while(((all_xor >> bit_pos_diff) & 1) != 1){
            bit_pos_diff++;
        }

        for(int i:nums){
            if(((i>> bit_pos_diff) & 1)==1){
                group_one ^=i;
            }
            else{
                group_two ^= i;
            }
        }

        return {group_one,group_two};
    }
};