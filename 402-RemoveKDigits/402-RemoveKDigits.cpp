class Solution {
public:
    string removeKdigits(string num, int k) {
        stack <char> ans;
        
        for(int i=0;i<num.size();i++)
        {
            while(k>0 && !ans.empty() && num[i]<ans.top() )
            {
               k--;ans.pop();
            }
            ans.push(num[i]);

        }
        while (k > 0) {
            ans.pop();
            k--;
        }
        string a="";
        while(!ans.empty())
        {
            a+=ans.top();
            ans.pop();
        }
        if(a==""){return "0";}
        reverse(a.begin(),a.end());
        int z=0;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]=='0')
            {
                z++;
                
            }
            else
            {
                break;
            }
        }
        if(a.size()==1){return a;}
        if(a==""){return "0";}
        if(a.substr(z)==""){return "0";}
       
        return a.substr(z);
        
        
    }
};