class Solution {
public:

     unordered_map<int, int> val2idx;
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int is, int ie, int ps, int pe) {
        if(is > ie || ps > pe) return nullptr;
        
        TreeNode* node = new TreeNode(postorder[pe]);
        
        int iroot = val2idx[postorder[pe]];
        // cout << "inorder's root at: " << iroot << endl;
        int leftSize = iroot-is;
        
        node->left = buildTree(inorder, postorder, is, iroot-1, ps, ps+leftSize-1);
        node->right = buildTree(inorder, postorder, iroot+1, ie, ps+leftSize, pe-1);
        
        return node;
    };
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        
        if(n == 0) return nullptr;
        
        for(int i = 0; i < n; ++i){
            val2idx[inorder[i]] = i;
        }
        
        return buildTree(inorder, postorder, 0, n-1, 0, n-1);
    }
};
// @lc code=end

