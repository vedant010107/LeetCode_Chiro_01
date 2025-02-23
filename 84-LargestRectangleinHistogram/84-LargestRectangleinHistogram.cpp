class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int ans = 0;

        for (int i=0; i<n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int a = heights[st.top()];
                st.pop();
                int p = st.empty() ? -1 : st.top();
                ans = max(ans, a*(i-p-1));
            }
            st.push(i);
        }

        while (!st.empty()) {
            int a = heights[st.top()];
            st.pop();
            int p = st.empty() ? -1 : st.top();
            ans = max(ans, a*(n-p-1));
        }
        return ans;
    }
};