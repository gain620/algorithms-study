/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// https://leetcode.com/problems/linked-list-cycle-ii
// youtube video : Why Floyd's cycle detection algorithm works? Detecting loop in a linked list.
// https://www.youtube.com/watch?v=LUm2ABqAs1w
class Solution {
public:
    ListNode* detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return NULL;
        ListNode* turtle = head;
        ListNode* rabbit = head;
        bool isCycle = false;
        
        while(turtle != NULL && rabbit != NULL && rabbit->next != NULL)
        {
            turtle = turtle->next;
            rabbit = rabbit->next->next;
            
            if(turtle == rabbit)
            {
                isCycle = true;
                break;
            }
        }
        
        if(!isCycle) return NULL;
        
        turtle = head;
        while(turtle != rabbit)
        {
            turtle = turtle->next;
            rabbit = rabbit->next;
        }
        
        return turtle;
    }
};