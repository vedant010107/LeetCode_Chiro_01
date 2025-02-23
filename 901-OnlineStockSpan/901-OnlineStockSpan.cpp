class StockSpanner {
public:

    stack<pair<int, int>> st;

    StockSpanner() {
        
    }
    
    int next(int price) {
        // 100,1 -> 80,1 -> 60,1 -> 70,2 -> 60,1 -> 75,4 -> 85,6
        // curr price included
        int span = 1;
        // if greater element found then stop
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        // push curr price
        st.push({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */