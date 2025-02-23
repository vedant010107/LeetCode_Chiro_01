class Solution {
public:
    string removeStars(string s) {
        vector <char> a;
        int top=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='*')
            {
                a.pop_back();
            }
            else
            {
                a.push_back(s[i]);
            }
        }
        string ans(a.begin(),a.end());
        return ans;

    }
};