class Solution {
public:
    int posIndex=-1;
    int findIndex(vector<int>& inorder,int val,int str,int end){
        for(int i=str;i<=end;i++){
            if(val == inorder[i])
                return i;
        }

        return -1;
    }
    TreeNode* buildTreeUtil(vector<int>& pos, vector<int>& inorder,int str,int end){
        if(str>end){
            return nullptr;
        }
        if(posIndex<0){
            return nullptr;
        }
        int val = pos[posIndex];
        int index=findIndex(inorder,pos[posIndex--],str,end);
        TreeNode* temp = new TreeNode(val,buildTreeUtil(pos,inorder,str,index-1),buildTreeUtil(pos,inorder,index+1,end));
        return temp;		
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        posIndex = inorder.size()-1;
        cout<<posIndex<<" ";
        return buildTreeUtil(postorder,inorder,0,posIndex);     
    }
};
// @lc code=end

