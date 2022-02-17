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
    ListNode *insertionSortList(ListNode *head)
    {
        ListNode* sortedList = head;
        head=head->next;
        sortedList->next = nullptr;
        while(head !=nullptr){
            ListNode* head1= head->next;
            ListNode *prev = nullptr;
            ListNode *curr = sortedList;
            while(curr != nullptr && curr->val <= head->val){
                prev = curr;
                curr = curr->next;
            }
            if(prev){
                prev->next = head;
                head->next = curr;
            }
            else{
                sortedList=head;
                sortedList->next = curr;
            }
            head=head1;
        }

        return sortedList;
    }
};
// @lc code=end
