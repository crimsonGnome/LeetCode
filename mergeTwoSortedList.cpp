//https://leetcode.com/problems/merge-two-sorted-lists/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode * answer, * temp;
        answer = new ListNode();
        temp = answer;
        while(list1 && list2){
            if(list1->val < list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2; 
                list2 = list2->next;
            }
            temp = temp->next;
        }
        if(list1){
            temp->next = list1;
        } else {
            temp->next = list2;
        }
        return answer->next;
    }
};