class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans; 
        stack<int> s;         
        ListNode* cur = head;
        while (cur) {
            ans.push_back(cur->val);  
            cur = cur->next;
        }
        
        int n = ans.size();  
        
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && ans[i] > ans[s.top()]) {
                int id = s.top();
                s.pop();
                ans[id] = ans[i];  
            }
            s.push(i);  
        }
        
        while (!s.empty()) { 
            int id = s.top();
            s.pop();
            ans[id] = 0;
        }
        return ans;
    } 
};