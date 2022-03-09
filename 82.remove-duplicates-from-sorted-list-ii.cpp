class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *temp = head;
        ListNode *prev = nullptr;
        if(temp == nullptr){
            return temp;
        }
        if(temp->next==nullptr){
            return temp;
        }
        ListNode *str = new ListNode(-1);
        ListNode *temp1=str;
        while(temp != nullptr && temp->next != nullptr){
            if(temp->val != temp->next->val){
                temp1->next=temp;
                temp1=temp1->next;
            }
            else{
                while(temp && temp->next && temp->val==temp->next->val){
                    temp=temp->next;
                }
            }
            temp=temp->next;
        }
        temp1->next=temp;     

        return str->next;
    }
};
