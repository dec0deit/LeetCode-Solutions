/*
 * @lc app=leetcode id=147 lang=cpp
 *
 * [147] Insertion Sort List
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(10);
        dummy = head;
        while(dummy != nullptr){
            ListNode* temp = head;
            while(temp->val > dummy->val && temp != dummy){
                swap(dummy->val,temp->val);
                temp = temp->next;
            }
            dummy = dummy->next;
        }

        return head;
    }
};
// @lc code=end

