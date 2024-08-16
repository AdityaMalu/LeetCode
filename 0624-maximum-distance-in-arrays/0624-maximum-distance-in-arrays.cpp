class Solution {
public:
    int maxDistance(vector<vector<int>>& a) {
        pair<int,int> max1 ={INT_MIN,INT_MIN}, max2 = {INT_MIN,INT_MIN};
        pair<int,int> min1 = {INT_MAX,INT_MAX}, min2 = {INT_MAX,INT_MAX};

        for(int i = 0 ; i < a.size() ; i++){
            int ind = 0, ind2 = a[i].size()-1;
            if(a[i][ind] <= min1.second){
                min2 = min1;
                min1 = {i, a[i][ind]};
            } else if(a[i][ind] <= min2.second) {
                min2 = {i, a[i][ind]};
            }
            if(a[i][ind2] >= max1.second){
                max2 = max1;
                max1 = {i, a[i][ind2]};
            } else if(a[i][ind2] >= max2.second) {
                max2 = {i, a[i][ind2]};
            }
        }

        if (max1.first != min1.first) {
            return max1.second - min1.second;
        } else {
            return max(max1.second - min2.second, max2.second - min1.second);
        }
    }
};
