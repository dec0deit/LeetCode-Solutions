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
    
    ListNode* findMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(slow != nullptr && fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
       }

       return slow;
    }
    
    ListNode* merge(ListNode *node, ListNode *node1){
        ListNode* temp = new ListNode(-1);
        ListNode* final = temp;
        
        while(node!=nullptr && node1!=nullptr){
            if(node->val <= node1->val){
                temp->next = node;
                node = node->next;
            }
            else{
                temp->next = node1;
                node1 = node1->next;
            }
            temp = temp->next;
        }
         while(node!=nullptr){
            temp->next = node;
            node=node->next;
            temp = temp->next;
        }
        while(node1!=nullptr){
            temp->next = node1;
            node1=node1->next;
            temp = temp->next;
        }
        return final->next;
    }

    ListNode* mergeList(ListNode* node){
        if(node == nullptr || node->next == nullptr)
            return node;
            
        ListNode* mid = findMid(node);
       
        if(mid == nullptr)
            return node;
       
        ListNode* right = mid->next;
        mid->next = nullptr;
        ListNode *left = mergeList(node);
        right = mergeList(right);
        return merge(left,right);
    }

    ListNode* sortList(ListNode* head) {
        return mergeList(head);
    }
};
// @lc code=end

