/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        ListNode* slow = head;
        ListNode* fast = head;
        while(slow && fast){
            slow = slow->next;

            fast = fast->next;
            if(fast)
                fast = fast->next;
            
            if(slow!=nullptr && slow == fast)
                break;
        }

        if(!slow || !fast){
            return nullptr;
        }

        fast = head;
        while(slow!=fast)
            slow = slow->next, fast = fast->next;

        return fast;
    }
};
// @lc code=end

