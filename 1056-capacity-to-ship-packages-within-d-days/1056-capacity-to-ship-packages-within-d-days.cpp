class Solution {
public:

    int check(vector<int>& weights, int capacity) {
        int days = 1; 
        int currentWeight = 0;

        for(int weight : weights) {
            if(currentWeight + weight > capacity) {
                days++;
                currentWeight = 0;
            }
            currentWeight += weight;
        }
        
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int minCapacity = *max_element(weights.begin(), weights.end());
        int maxCapacity = accumulate(weights.begin(), weights.end(), 0);

        while(minCapacity < maxCapacity) {
            int midCapacity = minCapacity + (maxCapacity - minCapacity) / 2;

            if(check(weights, midCapacity) > days) {
                minCapacity = midCapacity + 1;
            } else {
                maxCapacity = midCapacity;
            }
        }

        return maxCapacity;
    }
};
