/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode * mergeList(ListNode * x,ListNode * y){
        if(x==NULL){
            return y;
        }else if(y==NULL){
            return x;
        }
        ListNode * answer = NULL,*temp;
        ListNode * tem1 = x,*tem2 = y;
        while(tem1 != NULL && tem2 != NULL){
            if(tem1->val < tem2->val){
                if(answer == NULL){
                    answer = new ListNode (tem1->val);
                    temp = answer;
                }else{
                    temp->next = new ListNode(tem1->val);
                    temp = temp->next;
                }
                tem1 = tem1->next;
            }else{
                if(answer == NULL){
                    answer = new ListNode (tem2->val);
                    temp = answer;
                }else{
                    temp->next = new ListNode(tem2->val);
                    temp = temp->next;
                }
                tem2 = tem2->next;
            }
            
        }
        while(tem1 != NULL){
            if(answer == NULL){
                    answer = new ListNode (tem1->val);
                    temp = answer;
                }else{
                    temp->next = new ListNode(tem1->val);
                    temp = temp->next;
                }
                tem1 = tem1->next;
            
        }
        while(tem2 != NULL){
            if(answer == NULL){
                    answer = new ListNode (tem2->val);
                    temp = answer;
            }else{
                    temp->next = new ListNode(tem2->val);
                temp = temp->next;
            }
                tem2 = tem2->next;
            
        }
        return answer;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode * a = head;
        ListNode * b = head;
        while(b->next != NULL && b->next->next != NULL){
            a = a->next;
            b = b->next->next;
        }
        ListNode * x = sortList(a->next);
        a->next = NULL;
        ListNode * y = sortList(head);
        ListNode * answer = mergeList(x,y);
        return answer;
    }
};
// @lc code=end

