class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    
        unordered_map<int, int> freqs;
        for (int num : nums) {
            freqs[num]++;
        }

        
        auto comp = [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.second == b.second) {
                return a.first > b.first;
            }
            return a.second > b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> minHeap(comp);

        for (const auto& [num, count] : freqs) {
            minHeap.push({num, count});
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

     
        vector<int> topK;
        while (!minHeap.empty()) {
            topK.push_back(minHeap.top().first);
            minHeap.pop();
        }

        return topK;
    }
};