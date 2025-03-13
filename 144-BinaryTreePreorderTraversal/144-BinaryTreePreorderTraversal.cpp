class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector <int> preorder;
        if(root==NULL) return preorder;
        stack<TreeNode*>s;
        s.push(root);
        while(!s.empty())
        {
            root=s.top();s.pop();
            preorder.push_back(root->val);
            if(root->right!=NULL) s.push(root->right);
            if(root->left!=NULL) s.push(root->left);
        }
        return preorder;
    }
};