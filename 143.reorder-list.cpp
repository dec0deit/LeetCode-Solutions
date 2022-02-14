/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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

    ListNode* reverse(ListNode* head){

        ListNode* next = nullptr;
        ListNode* prev = nullptr;
        ListNode * curr = head;
        while(curr != nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
    void reorderList(ListNode* head) {
        if(head == nullptr)
            return ;
        
        if(head->next == nullptr)
            return ;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        slow = reverse(slow);

        ListNode* curr = head;
        ListNode* curr1 = head->next;
        while(slow != nullptr && curr1 != nullptr){
            curr->next = slow;
            slow = slow->next;
            curr = curr->next;
            curr->next=curr1;
            curr1 = curr1->next;
            curr = curr->next;
        }
        if(curr1 != nullptr)
            curr->next = curr1;

        else if(slow != nullptr)
            curr->next = slow;
    }


};
// @lc code=end

