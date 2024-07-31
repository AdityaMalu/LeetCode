class Solution {
public:
    int recc(vector<vector<int>>& books, int ind,int rem_width,int curr_height,int shelfWidth,vector<vector<int>> &dp){
        if(ind >= books.size()) return curr_height;

        if( dp[ind][rem_width] != -1) return dp[ind][rem_width];

        int bw = books[ind][0];
        int bh = books[ind][1];

        int keep =INT_MAX,skip = INT_MAX;
        if(bw <= rem_width){
            keep = recc(books,ind+1,rem_width-bw,max(bh,curr_height),shelfWidth,dp);
        }

        skip = curr_height + recc(books,ind+1,shelfWidth - bw, bh,shelfWidth,dp);

        return  dp[ind][rem_width] = min(keep,skip);

    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        vector<vector<int>> dp(books.size(),vector<int>(shelfWidth+1,-1));
        return recc(books,0,shelfWidth,0,shelfWidth,dp);
    }
};