#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 

        stack<int> st; 
        int wa = 0, n = height.size();

        for (int i = 0; i < n; i++) {
            while (!st.empty() && height[i] > height[st.top()]) {
                int top = st.top();
                st.pop();

                if (st.empty()) break; 

                int left = st.top();
                int l = i - left - 1;
                int th = min(height[left], height[i]) - height[top];

                wa += l * th;
            }
            st.push(i);
        }

        cout << flush; 
        return wa;
    }
};
