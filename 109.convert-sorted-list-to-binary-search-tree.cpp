class Solution { 
public:
    TreeNode* finalQuestion(ListNode** head,int n){
        if(n<=0){
            return nullptr;
        }
        TreeNode* left = finalQuestion(head,n/2);
        TreeNode* root = new TreeNode();
        root->val = (*head)->val;
        *head = (*head)->next;
        root->left = left;
        TreeNode* right = finalQuestion(head,n - n / 2 - 1);
        root->right = right;
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* temp = head;
        int count=0;
        while(temp != nullptr){
            count++;
            temp = temp->next;
        }
        return finalQuestion(&head, count);
    }   
};
// @lc code=end

