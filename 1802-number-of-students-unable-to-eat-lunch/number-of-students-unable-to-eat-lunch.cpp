class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int> count(2,0);
        for(int i:students){
            count[i]++;
        }
        int rem = sandwiches.size();
        for(int i :sandwiches){
            if(count[i] == 0){
                break;
            }
            if(rem == 0){
                break;
            }
            count[i]--;
            rem--;
        }
        return rem;
    }
};