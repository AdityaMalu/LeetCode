class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>> cp(n);

        for(int i = 0 ; i < n  ; i++){
            cp[i] = {capital[i] , profits[i]};
        }

        sort(cp.begin(),cp.end());

        priority_queue<int> pq;

        int curr = 0;
        for(int i = 0 ; i < k ; i++){
            while(curr < n && cp[curr].first <= w){
                pq.push(cp[curr].second);
                curr++;
            }

            if(!pq.empty()){
                w+=pq.top();
                pq.pop();
            }
            else{
                break;
            }
        }
        return w;
    }
};