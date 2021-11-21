#include <bits/stdc++.h>
using namespace std;
using ll=long long int; 

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution 
{
    public:
        TreeNode* prev = nullptr;
    
        int isBST(TreeNode* node)
        {
            if(node == nullptr){
                return true;
            }
            
            cout<<"working"<<endl;
            
            if(prev != nullptr){
                cout<<"dfkfmnklsd";
            }
            bool res = isBST(node->left);
            
            
            if(prev != nullptr && prev->val >= node->val){
                cout<<"fmknfklsdn";
                return false;
            }
            
            prev = node;   
            
            bool res1 = isBST(node->right);
            return res && res1;
        
        }
    
        bool isValidBST(TreeNode* root) {
            return isBST(root);
        }
};
void solve(){
  
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}