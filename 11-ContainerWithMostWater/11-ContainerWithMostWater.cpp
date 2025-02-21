class Solution {
public:
    int maxArea(vector<int>& height) {
        int mx=0;int l=0,r=height.size()-1;
        while(l<=r)
        {
            mx=max(min(height[l],height[r])*(r-l),mx);
            if(height[l]>=height[r])
            {
                r--;
            }
            else{l++;}
        }
        return mx;
    }
};