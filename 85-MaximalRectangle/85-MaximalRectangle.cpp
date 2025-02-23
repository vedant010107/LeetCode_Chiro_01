class Solution {
public:

    vector<int> nse(vector<int>& arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--) {
            while (s.top() != -1 && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }

        return ans;
    }

    vector<int> pse(vector<int>& arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            while (s.top() != -1 && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }

        return ans;
    }

    int coder(vector<int>& h, int n) {
        vector<int> nx = nse(h, n);
        vector<int> prv = pse(h, n);

        int area = 0;

        for (int i = 0; i < n; i++) {
            int l = h[i];
            if (nx[i] == -1) {
                nx[i] = n;
            }
            int b = nx[i] - prv[i] - 1;
            int na = l * b;
            area = max(area, na);
        }

        return area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if (n == 0) return 0;

        int m = matrix[0].size();
        vector<int> h(m, 0);

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(matrix[i][j] == '1'){h[j]++;}
                else{h[j]=0;}
            }

            ans = max(ans, coder(h, m));
        }

        return ans;
    }
};