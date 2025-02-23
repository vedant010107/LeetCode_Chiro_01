#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); // Optimize I/O

        stack<int> st; // Monotonic decreasing stack
        int wa = 0, n = height.size();

        for (int i = 0; i < n; i++) {
            while (!st.empty() && height[i] > height[st.top()]) {
                int top = st.top();
                st.pop();

                if (st.empty()) break; // No left boundary

                int left = st.top();
                int width = i - left - 1;
                int boundedHeight = min(height[left], height[i]) - height[top];

                wa += width * boundedHeight;
            }
            st.push(i);
        }

        cout << flush; // Flush buffer for each test case
        return wa;
    }
};
