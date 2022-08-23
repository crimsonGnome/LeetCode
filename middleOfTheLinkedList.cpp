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
    ListNode* middleNodeHelper(ListNode* head, ListNode* half, int counter ){
        // base case
        if(head == nullptr){
            return half;
        }
        //advance the half node
        if(counter % 2 == 1){
            return middleNodeHelper(head->next, half->next, counter +1);
        }
        return middleNodeHelper(head->next, half, counter +1);
    
    }
    ListNode* middleNode(ListNode* head) {
        return middleNodeHelper(head->next, head, 1);
    }
};