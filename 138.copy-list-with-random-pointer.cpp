/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr){
            return nullptr;
        }
        Node* temp = head;
        while(temp != nullptr){
            Node* temp1 = new Node(temp->val);
            Node* temp2 = temp->next;
            temp->next = temp1;
            temp1->next = temp2;
            temp = temp2;
        }
        temp = head;
        while(temp != nullptr && temp->next != nullptr){
            if(temp->random )
            temp->next->random = temp->random->next;
            temp = temp->next->next;
        }

        Node* odd = head;
        Node* even = head->next;
        Node* final1 = even;
        while(odd->next != nullptr && even->next!=nullptr){
            odd->next = even->next;
            even->next = even->next->next;
            odd=odd->next;
            even=even->next;
        }

        if(odd){
            odd->next = nullptr;
        }

        if(even->next){
            even->next = nullptr;
        }

        return final1;
    }
};
// @lc code=end

