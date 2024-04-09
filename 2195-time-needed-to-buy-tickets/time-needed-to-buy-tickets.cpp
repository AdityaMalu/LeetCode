class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans = 0, i = 0;
        while(tickets[k] != 0){
            if(tickets[i%tickets.size()] != 0)
            {
                tickets[i%tickets.size()]--;
                cout<<tickets[i%tickets.size()]<<" ";
                ans++;
            }
            i++;
        }
        return ans;
    }
};