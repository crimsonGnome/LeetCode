// https://leetcode.com/problems/linked-list-cycle/

// my initial solution 
class Solution {
public:
    bool helperHasCycle(ListNode * ptr,std::set<ListNode*>& linked){
        if(ptr == NULL) return false;
        auto found = linked.find(ptr);
        if(found == linked.end()){
            linked.insert(ptr);
            return helperHasCycle(ptr->next, linked);
        }
        return true;
    }
    
    bool hasCycle(ListNode *head) {
        std::set<ListNode*> linked;
        return helperHasCycle(head, linked);
        
    }
};

// way better my solution
class Solution {
public:
    bool hasCycle(const ListNode const *head) {
        if (!head)
            return false;
        
        const ListNode* slow = head;
        const ListNode* fast = head->next;
        
        while (slow != fast) {
            if (!fast || !fast->next)
                return false;
            
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return true;
    }
    
//     bool hasCycle(ListNode *head) {
        
//     }
};