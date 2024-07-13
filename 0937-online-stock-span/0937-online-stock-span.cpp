class StockSpanner {
public:

    stack<int>stk;
    stack<int>freq;
    StockSpanner() {
        
    }
    
    int next(int price) {
        if(stk.empty()){
            stk.push(price);
            freq.push(1);
            return 1;
        }
        else if(stk.top()>price){
            stk.push(price);
            freq.push(1);
            return 1;
        }
        else{
            int temp =1;
            while(!stk.empty() && stk.top()<=price){
                stk.pop();
                temp+=freq.top();
                freq.pop();
            }
            stk.push(price);
            freq.push(temp);
            return temp;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */