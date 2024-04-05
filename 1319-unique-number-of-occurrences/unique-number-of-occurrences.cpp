class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        vector<int> res;
        sort(arr.begin(),arr.end());
        int count=1;
        for(size_t i{1};i<arr.size();i++)
        {
        
            if(arr[i]==arr[i-1])
            {
                count++;
            }
            else{
                res.push_back(count);
                count = 1;
            }
            
        }
         res.push_back(count);
        
        sort(res.begin(),res.end());
        for(size_t i=1;i<res.size();i++)
        {
            if(res[i]==res[i-1])
                return false;
        }
        return true;
    }
};
