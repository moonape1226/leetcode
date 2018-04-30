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
    /* Floyd-Cycle-Detection-Algorithm */
    ListNode *detectCycle(ListNode *head) {
        ListNode *oneStep = head, *twopStep = head;
        bool isCircle = false;
        
        if(head == NULL || head->next == NULL)
        {
            return NULL;
        }
        
        while(twopStep->next != NULL && twopStep->next->next != NULL)
        {
            oneStep = oneStep->next;
            twopStep = twopStep->next->next;
            
            if(oneStep == twopStep)
            {
                isCircle = true;
                break;
            }
        }
        
        if(!isCircle)
            return NULL;
        
        while(head != oneStep)
        {
            head = head->next;
            oneStep = oneStep->next;
        }
        
        return oneStep;
    }
};