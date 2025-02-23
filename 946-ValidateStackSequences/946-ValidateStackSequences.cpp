class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int j=0;
        stack <int> ans;
        for(int i=0;i<pushed.size();i++)
        {
            ans.push(pushed[i]);
            while(!ans.empty() && ans.top()==popped[j])
            {
                ans.pop();
                j++;
            }
        }
        if(ans.empty()){return true;}
        else {return false;}
    }
};