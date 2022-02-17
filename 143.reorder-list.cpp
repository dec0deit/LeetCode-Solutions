/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
 */

// @lc code=start
/**
 * Definition for singly-linked list->
 * struct ListNode* {
 *     int val;
 *     ListNode* *next;
 *     ListNode*() : val(0), next(nullptr) {}
 *     ListNode*(int x) : val(x), next(nullptr) {}
 *     ListNode*(int x, ListNode* *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* reverse(ListNode* head){

        ListNode* next = nullptr;
        ListNode* prev = nullptr;
        ListNode*  curr = head;
        while(curr != nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode*  fast=head;
        ListNode* slow=head;
        //finding mid
        while(fast->next !=nullptr && fast->next->next !=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* cur=slow->next;
        slow->next=nullptr;
        ListNode* head2=nullptr;
        //reverse 2nd half
        while(cur!=nullptr){
            ListNode* temp=cur->next;
            cur->next=head2;
            head2=cur;
            cur=temp;
        }
        ListNode* one=head;
        ListNode* two=head2;

        ListNode* temp=nullptr;
        ListNode* temp2=nullptr;
        while(one !=nullptr && two !=nullptr){
             temp=one->next;
            one->next=two;
           temp2=two->next;
            two->next=temp;
            two=temp2;
            one=temp;
        }
    }


};
// @lc code=end

